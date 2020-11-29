/* fork.c demonstrate fork() system call */

#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#define MAX_COUNT 10
void ChildProcess();  /* child process prototype */
void ParentProcess(); /* parent process prototype */

int main()
{
  pid_t pid;
  pid_t ppid = getpid(); /* get parent process ID */
  pid = fork();          /* create a child */
  if (pid == 0)          /* means a child process*/
    ChildProcess();
  else
    ParentProcess();
  return 0;
}

void ChildProcess()
{
  int i;
  for (i = 1; i <= MAX_COUNT; i++)
    printf(" This line is from child process value = %d\n", i);
  printf(" *** Child process is done ***\n");
}
void ParentProcess()
{
  int i;
  for (i = 1; i <= MAX_COUNT; i++)
    printf("This line is from parent process value = %d\n", i);
  printf("*** Parent is done ***\n");
}
