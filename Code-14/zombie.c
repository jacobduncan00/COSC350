/* zombie.c: create a zombie process */
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

int main(void)
{
  int pid;
  pid = fork();
  /* parent sleep 100 sec */
  if (pid > 0)
  {
    sleep(100);
  }
  /* a child terminate parent don't have time to save a child info */
  /* child remains as a zombie */
  else
  {
    exit(0);
  }
}
