#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void *counter()
{
  int i = 0;
  while (1)
  {
    printf("%d\n", i);
    i++;
    sleep(1);
    if (i == 100)
    { //once this thread reaches 100
      /*
            if this thread calls an exit(...)
            then main process will terminate (this thread will as well)
            no need for pthread_cancel(...)
            */
      exit(0);
    }
  }
}

int main()
{

  //Creating our threads
  pthread_t count_t;

  //threads for calculating the sum/factorial
  int count_pt = pthread_create(&count_t, NULL, counter, NULL);

  if (count_pt != 0)
  { //debugging, ignore this as its not necessary
    printf("Threads did not create successfully\n");
  }

  while (1)
  { //loop for original program output
    printf("I am original program\n");
    sleep(1);
  }

  if (pthread_join(count_t, NULL) != 0)
  { //suspend until counter terminates
    printf("Increase thread broke\n");
    return 0;
  }

  return 0;
}
