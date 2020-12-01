/*
  Jacob Duncan
  Lab 10
  Task 3
  task3.c
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <pthread.h>

#define SIZE 10
typedef int semaphore;
semaphore mutex = 0;
semaphore empty = 2;
semaphore full = 1;

int semid;
int buffer[SIZE];
int ind = 0;

void printBuffer() {
    int j;
    for (j = 0; j < 10; j++)
    {
      printf("%d ", buffer[j]);
    }
    printf("\n\n");
}

void insert(int i)
{
  if (ind < 10)
  {
    buffer[ind++] = i;
  }
  else
  {
    printf("No space to insert!\n");
  }
}

int removeItem()
{
  if (ind > 0)
  {
    int temp = buffer[ind - 1];
    ind--;
    buffer[ind] = 0;
    return temp;
  }
  else
  {
    printf("Nothing to remove!\n");
  }
}

void up(int semNum)
{
  struct sembuf up = {semNum, 1, 0};
  if (semop(semid, &up, 1) == -1)
  {
    perror("ERROR [UP]: semop() error!\n");
    exit(1);
  }
}

void down(int semNum)
{
  struct sembuf down = {semNum, -1, 0};
  if (semop(semid, &down, 1) == -1)
  {
    perror("ERROR [DOWN]: semop() error!\n");
    exit(1);
  }
}

void *producer()
{
  int item;
  while (1)
  {
    item = rand() % 9 + 1; // random number between 1 - 10 to insert into buffer
    down(empty);
    down(mutex);
    printf("Producing: %d\n", item);
    insert(item);
    up(mutex);
    up(full);
    printBuffer();
    sleep(1);
  }
}

void *consumer()
{
  int i;
  while (1)
  {
    down(full);
    down(mutex);
    i = removeItem();
    up(mutex);
    up(empty);
    printf("Consuming: %d\n", i);
    int j;
    for (j = 0; j < 10; j++)
    {
      printf("%d ", buffer[j]);
    }
    printf("\n");
    sleep(2);
  }
}

int main(int argc, char *argv[])
{
  key_t key;
  union semun arg;
  pthread_t T[2];

  if ((key = ftok("task3.c", 'B')) == -1)
  {
    perror("ERROR [MAIN]: ftok() error!\n");
    exit(1);
  }

  // Creating semaphores
  if ((semid = semget(key, 3, 0666 | IPC_CREAT)) == -1)
  {
    perror("ERROR [MAIN]: semget() error!\n");
    exit(1);
  }
  
  arg.val = 1; // testing val 1
  if (semctl(semid, mutex, SETVAL, arg) == -1)
  {
    perror("ERROR [MAIN]: semctl() error!\n");
    exit(1);
  }

  arg.val = SIZE; // val 10
  if (semctl(semid, empty, SETVAL, arg) == -1)
  {
    perror("ERROR [MAIN]: semctl() error!\n");
    exit(1);
  }

  arg.val = 0; // val 0
  if (semctl(semid, full, SETVAL, arg) == -1)
  {
    perror("ERROR [MAIN]: semctl() error!\n");
    exit(1);
  }

  pthread_create(&T[0], NULL, producer, (void *)&semid);
  pthread_create(&T[1], NULL, consumer, (void *)&semid);
  pthread_join(T[0], NULL);
  pthread_join(T[1], NULL);
  if (semctl(semid, 0, IPC_RMID, arg) == -1)
  {
    perror("ERROR [MAIN]: semctl() error!\n");
    exit(1);
  }
  return 0;
}
