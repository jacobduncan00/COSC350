/*
 Jacob Duncan
 Lab 10
 Task 2
 task2.c
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <pthread.h>

int buffer[10];
int index = 0;

void producer()
{
  while (1)
  {
    int item = rand() % 10;
    if (index < 10)
    {
      buffer[index++] = item;
    }
    else
    {
      printf("No space in buffer to insert! \n");
    }
    printf("Producing %d\n", item);
    int i;
    for (i = 0; i < 10; i++)
    {
      printf("%d ", buffer[i]);
    }
    printf("");
    sleep(1);
  }
}
void consumer()
{
  while (1)
  {
    int temp = buffer[index - 1];
    if (index >= 0)
    {
      index--;
      buffer[index] = 0;
    }
    else
    {
      printf("No value to remove from buffer!\n");
    }
    printf("Consuming %d\n", temp);
    int i;
    for (i = 0; i < 10; i++)
    {
      printf("%d ", buffer[i]);
    }
    printf("");
    sleep(2);
  }
}

int main(int argc, char *argv[])
{
  pthread_t T[2];

  pthread_create(&T[0], NULL, producer, NULL);
  pthread_create(&T[1], NULL, consumer, NULL);

  pthread_join(T[0], NULL);
  pthread_join(T[1], NULL);

  return 0;
}
