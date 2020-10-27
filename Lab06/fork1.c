/*
Jacob Duncan
Lab06
Task 2
fork1.c
*/

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int stringtoint(char *c)
{
  int i = 0;
  long int num = 0;
  while (c[i] != '\0')
  {
    num = 10 * num + (c[i] - '0');
    i++;
  }
  return num;
}

int main(int argc, char *argv[])
{
  pid_t pid;
  char *message;
  int n;
  if (argc != 5)
  {
    printf("ERROR: Invalid number of arguments passed, expected 4\n");
    printf("Example: ./fork [Nc] [Np] [Tc] [Tp]\n");
    return -1;
  }

  int Nc = stringtoint(argv[1]);
  int Np = stringtoint(argv[2]);
  int Tc = stringtoint(argv[3]);
  int Tp = stringtoint(argv[4]);

  printf("Starting fork\n");
  pid = fork();

  int sleepTime;

  switch (pid)
  {
  case -1:
    perror("fork failed");
    exit(1);
  case 0:
    message = "This is the child";
    n = Nc;
    sleepTime = Tc;
    break;
  default:
    message = "This is the parent";
    n = Np;
    sleepTime = Tp;
    break;
  }
  for (; n > 0; n--)
  {
    puts(message);
    sleep(sleepTime);
  }
  exit(0);
}
