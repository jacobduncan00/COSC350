/* fileshare3.c child process run different program */
#include <unistd.h>
#include <fcntl.h>
#include <ctype.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>

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
  input = open(argv[1], O_RDONLY); // Open file passed
  pid_t pid;
  pid = vfork(); /* create a child */
  if (pid == 0)  /* child process */
  {
    execv("reverse", argv); /* child process run different program */
    _exit(0);
  }
  else /* parent */
  {
    if ((pout = open("parent.txt", O_WRONLY | O_CREAT, S_IREAD | S_IWRITE)) == -1)
    {
      error_sys("Output File Create Error");
    }
    lseek(input, 0, SEEK_SET);
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
