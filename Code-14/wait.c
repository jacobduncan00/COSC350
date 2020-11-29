/*wait.c demonstrate wait() system call */
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/types.h>

#define MAX_COUNT 1000
#define BUF_SIZE 100

void main(void)
{
  pid_t pid1, pid, p1;
  int status;
  int i;
  char buf[BUF_SIZE];
  printf("*** Parent is about to fork ***\n");
  if ((pid1 = fork()) < 0)
  {
    printf("Failed to fork process 1\n");
    exit(1);
  }
  else if (pid1 == 0) /* child's part */
  {
    p1 = getpid();
    for (i = 1; i < MAX_COUNT; i++)
    {
      sprintf(buf, "child %d is running\n", p1);
      write(1, buf, strlen(buf));
    }
    _exit(0);
  }
  else /* parent's part */
  {
    sprintf(buf, "*** Parent enters waiting status .....\n");
    write(1, buf, strlen(buf));
    pid = wait(&status); /*wait for child finish it's job */
    if (WIFEXITED(status))
    {
      printf(" A child process terminate normally\n");
    }
    else
    {
      printf(" A child process terminate abnormally\n");
    }
    sprintf(buf, "*** Parent detects process %d was done ***\n", pid);
    write(1, buf, strlen(buf));
    printf("*** Parent exits ***\n");
    exit(0);
  }
}
