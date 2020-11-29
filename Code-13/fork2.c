/* fork2.c */
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#define MAX_COUNT 10
#define BUF_SIZE 100

int main(void)
{
  pid_t pid, ppid;
  int i;
  char buf[BUF_SIZE];
  ppid = getpid(); /* this is parent process ID */
  fork();          /*create a child */
  for (i = 1; i <= MAX_COUNT; i++)
  {
    pid = getpid();
    if (pid == ppid) /* parent works here */
    {
      sprintf(buf, "Parent(%d) process executed %d times\n", ppid, i);
      write(1, buf, strlen(buf));
    }
    else /* child work here */
    {
      sprintf(buf, "Child(%d) process executed %d times\n", pid, i);
      write(1, buf, strlen(buf));
    }
  }
  return 0;
}
