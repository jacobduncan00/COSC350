//fileshare1.c

#include <unistd.h>
#include <fcntl.h>
#include <ctype.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>

void error_sys(char *msg)
{
  printf("%s\n", msg);
  exit(1);
}

int main(int argc, char *argv[])
{
  int input, chout, nbyte, pout;
  int i;
  char buff[1];

  if (argc != 2)
  {
    error_sys("usage: Argument number error\n");
  }

  input = open(argv[1], O_RDONLY);
  pid_t pid;
  pid = fork(); /* create a child */

  if (pid == 0) /* child process */
  {
    if ((chout = open("child.txt", O_WRONLY | O_CREAT, S_IREAD | S_IWRITE)) == -1)
    {
      error_sys("Output File Create Error");
    }
    while ((nbyte = read(input, buff, 1)) > 0)
    {
      if (write(chout, buff, 1) != 1)
      {
        error_sys("Write Error");
      }
    }
  }
  else /* parent */
  {
    if ((pout = open("parent.txt", O_WRONLY | O_CREAT, S_IREAD | S_IWRITE)) == -1)
    {
      error_sys("Output File Create Error");
    }
    while ((nbyte = read(input, buff, 1)) > 0)
    {
      if (write(pout, buff, 1) != 1)
      {
        error_sys("Write Error");
      }
    }
  }

  return 0;
}
