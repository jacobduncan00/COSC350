#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

void handler(int sig)
{
  if (sig == SIGUSR1)
  {
    printf("I am terminated by my parents\n"); //child exits
    exit(0);
  }
}

int main()
{

  int status = 0;

  pid_t pid = fork();
  if (pid == 0) //child process
  {

    signal(SIGUSR1, handler); //set signal handler in child

    while (1)
    {
      printf("child is running\n");
      sleep(1);
    }
  }
  else if (pid > 0) //parent process
  {

    int i;
    for (i = 0; i < 10; i++)
    {
      printf("parent is running\n");
      sleep(1);
    }

    kill(pid, SIGUSR1); //send signal (SIGUSR1) to child

    for (i = 0; i < 10; i++)
    {
      printf("parent is running\n");
      sleep(1);
    }
    exit(0);
  }

  return 0;
}
