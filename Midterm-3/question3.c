#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void *runForever()
{
  int incrementer = 0;
  while (1)
  {
    printf("%d\n", incrementer);
    incrementer++;
    sleep(1);
    if (incrementer == 10)
    {
      _exit(0); // Using exit() or _exit() the entire process terminates.
    }
  }
}

int main()
{
  pthread_t T;
  int counter = pthread_create(&T, NULL, runForever, NULL);
  if (counter)
  {
    printf("Threads did not create successfully\n");
    exit(-1);
  }

  while (1)
  {
    printf("I am original program\n");
    sleep(1);
  }

  if (pthread_join(T, NULL) != 0) // Once incrementer of function reaches 100, run this if statement and return 0 to main, terminating the original program
  {
    printf("function reached 100!\n");
    return 0;
  }

  return 0;
}
