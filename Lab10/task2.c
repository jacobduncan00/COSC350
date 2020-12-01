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
int ind = 0; // don't know if we need this global variable for the buffer index
             // probably a better way of doing this

void printBuffer(){
    int j;
    for (j = 0; j < 10; j++)
    {
      printf("%d ", buffer[j]);
    }
    printf("\n\n");
}

// Makes a random number between 1 and 9 to put into the buffer
int produceItem() {
  return rand() % 9 + 1;
}

void producer()
{
  int item;
  while (1)
  {
    item = produceItem();
    if (ind < 10)
    {
      buffer[ind++] = item;
      printf("Producing %d\n", item);
      printBuffer();
    }
    else
    {
      printf("No space in buffer to insert! \n");
    }
    sleep(1);
  }
}

void consumer()
{
  while (1)
  {
    int temp = buffer[ind - 1];
    if (ind > 0)
    {
      ind--;
      buffer[ind] = 0;
      printf("Consuming %d\n", temp);
    }
    else
    {
      printf("No value to remove from buffer!\n");
    }
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
