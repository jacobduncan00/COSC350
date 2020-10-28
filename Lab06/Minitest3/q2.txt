#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

#define CHILD_MAX 100
#define SLEEP_TIME 1
int finish = 0;

int main()
{
  pid_t pid = fork();
  pid_t cpid;
  switch (pid)
  {
  case -1:
    perror("fork failed");
    exit(1);
  case 0:
    cpid = fork();
    if (cpid != 0)
    {
      for (int i = 0; i < CHILD_MAX; i++)
      {
        printf("I am your child\n");
        sleep(SLEEP_TIME);
      }
      finish = 1;
      exit(0);
    }
    else
    {
      while (finish == 0)
      {
        printf("I am your granchild\n");
        sleep(SLEEP_TIME);
      }
    }
    break;
  default:
    while (wait(NULL) == 0)
    {
      printf("I am your parent\n");
      sleep(SLEEP_TIME);
    }
    printf("I finished my job\n");
    break;
  }
  exit(0);
}
