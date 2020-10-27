/*
Jacob Duncan
Lab06
Task 4
child.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>

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
  if (argc != 3)
  {
    printf("ERROR: Expected 3 arguments!\n");
    printf("Example: ./child [message] [Nc] [Tc]\n");
    return -1;
  }
  pid_t pid = getpid();
  char *message = argv[0];
  int Nc = stringtoint(argv[1]);
  int Tc = stringtoint(argv[2]);
  int n = Nc;

  for (; n > 0; n--)
  {
    printf("%s | pid: %d\n", message, pid);
    sleep(Tc);
  }

  exit(37);
}
