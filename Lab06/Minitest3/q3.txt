#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

int isDigit(int c)
{
  if (c >= 48 && c <= 57)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

int main(int argc, char *argv[])
{
  pid_t pid;
  int inputFile, childOutput, parentOutput;
  char buf;
  int childOffset = 0;
  int parentOffset = 0;

  if (argc != 2)
  {
    printf("ERROR: Invalid amount of arguments passed, expected 2\n");
    printf("Ex: ./task5 [inputFile]\n");
    exit(1);
  }

  inputFile = open(argv[1], O_RDONLY);
  if (inputFile < 0)
  {
    printf("ERROR: Input file error!");
    exit(1);
  }
  parentOutput = open("parentOutput.txt", O_WRONLY | O_CREAT | O_EXCL, 0666);
  childOutput = open("childOutput.txt", O_WRONLY | O_CREAT | O_EXCL, 0666);
  if (childOutput < 0 || parentOutput < 0)
  {
    printf("ERROR: Output file error!");
    exit(1);
  }

  pid = fork();
  int nr;

  switch (pid)
  {
  case -1:
    perror("ERROR: Fork failed!");
    exit(1);
  case 0:
    umask(0);

    lseek(inputFile, 0, SEEK_SET);
    while ((nr = read(inputFile, &buf, 1)) > 0)
    {
      write(childOutput, &buf, nr);
    }
    close(childOutput);
    break;
  default:
    umask(0);
    lseek(inputFile, 0, SEEK_SET);
    while ((nr = read(inputFile, &buf, 1)) > 0)
    {
      write(parentOutput, &buf, nr);
    }
    close(parentOutput);
    break;
  }

  close(inputFile);
  close(childOutput);
  close(parentOutput);
  exit(0);
}
