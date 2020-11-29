#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void Bye()
{
  printf("Bye!\n");
}

void *thread1()
{
  pthread_t id = pthread_self();
  pthread_cleanup_push(Bye, NULL);
  while (1)
  {
    pthread_testcancel();
    sleep(1);
  }
  pthread_cleanup_pop(0);
}

void *thread2(void *pthr) // This function needs the id of the first thread
{
  pthread_t id = (pthread_t)pthr;
  int counter = 0;
  while (1)
  {
    printf("Counter: %d", counter);
    counter++;
    if (counter == 10)
    {
      pthread_cancel(id);
    }
    sleep(1);
  }
}

int main()
{
  pthread_t T1;
  pthread_t T2;

  int T1PTR = pthread_create(&T1, NULL, thread1, NULL);
  int T2PTR = pthread_create(&T2, NULL, thread2, &T1);

  if (T1PTR != 0 || T2PTR != 0)
  {
    printf("Could not create both threads!\n");
    return 0;
  }

  pthread_join(T1, NULL);
  pthread_join(T2, NULL);

  return 0;
}
