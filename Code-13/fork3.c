/* fork3.c */

#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>

int glob = 6; /*global variable */

int main()
{
  int local;
  pid_t pid;
  local = 88; /*local variable */
  printf("before vfork\n");

  if ((pid = vfork()) < 0) /* create a child */
  {
    printf("vfork error");
    exit(1);
  }
  else if (pid == 0) /* for child process */
  {
    glob++;
    local++;
    printf("Child pid = %d, global = %d, local = %d\n", getpid(), glob, local);
    _exit(0);
  }

  /* for parent process */
  printf(" Parent pid = %d, global = %d, local = %d\n", getpid(), glob, local);
  exit(0);
}
