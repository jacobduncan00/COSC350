/* zombie01.c: create a zombie process */
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

int main(void)
{
  int pid, pid1;
  pid = fork(); //create the first child
  if (pid > 0)
  {
    pid1 = fork(); //create the second child
    if (pid1 > 0)  //parent runs forever
    {
      wait();
      while (1)
        ;
    }
    else // for second child
    {
      _exit(0);
    }
  }
  else //for first child
  {
    _exit(0);
  }
}
