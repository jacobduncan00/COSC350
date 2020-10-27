/*
Jacob Duncan
Lab06
Task 5
task5.c
*/

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

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
  int inputFile, childOutput, parentOutput, exitCode;
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
  parentOutput = open("parent.txt", O_WRONLY | O_CREAT | O_EXCL, 0755);
  childOutput = open("child.txt", O_WRONLY | O_CREAT | O_EXCL, 0755);
  if (childOutput < 0 || parentOutput < 0)
  {
    printf("ERROR: Output file error!");
    exit(1);
  }

  pid = fork();

  switch (pid)
  {
  case -1:
    perror("ERROR: Fork failed!");
    exit(1);
  case 0:
    exitCode = 37;
    while (pread(inputFile, &buf, 1, childOffset) == 1)
    {
      if (isDigit(buf) == 0)
      {
        write(childOutput, &buf, 1);
      }
      childOffset++;
    }
    break;
  default:
    exitCode = 0;
    while (pread(inputFile, &buf, 1, parentOffset) == 1)
    {
      if (isDigit(buf) == 1)
      {
        write(parentOutput, &buf, 1);
      }
      parentOffset++;
    }
    break;
  }

  close(inputFile);
  close(childOutput);
  close(parentOutput);

  if (pid != 0)
  {
    int statNum;
    pid_t cpid;

    cpid = wait(&statNum);

    printf("Child has finished | PID = %d\n", cpid);
    if (WIFEXITED(statNum))
    {
      printf("Child exited with code %d\n", WEXITSTATUS(statNum));
    }
    else
    {
      printf("Irregular child termination\n");
    }
  }
  exit(exitCode);
}
