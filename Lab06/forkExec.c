/*
  * Jacob Duncan
  * Lab06
  * Task 4
  * forkExec.c
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

  printf("fork program starting\n");
  pid = fork();

  int sleepTime;

  switch (pid)
  {
  case -1:
    perror("fork failed");
    exit(1);
  case 0:
    printf("Exec returned: %d\n", execlp("./child", "This is the child", argv[1], argv[3], (char *)0));
    break;
  default:
    message = "This is the parent";
    n = Np;
    sleepTime = Tp;
    break;
  }

  for (; n > 0; n--)
  {
    printf("%s pid: %d\n", message, pid);
    sleep(sleepTime);
    if (pid != 0)
    {
      printf("Waiting for child process to terminate.\n");
      wait(0);
      printf("Child process terminated.\n");
    }
  }
  return 0;
}
