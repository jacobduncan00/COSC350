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

int main(int argc, char **argv)
{
  pid_t pid;
  int n;
  if (argc != 3)
  {
    printf("ERROR: Expected 3 arguments!\n");
    printf("Example: ./child  [message] [Nc] [Tc]\n");
    return -1;
  }

  char *message = argv[1];
  int Nc = stringtoint(argv[2]);
  int Tc = stringtoint(argv[3]);

  for (; Nc > 0; Nc--)
  {
    printf("%s  pid: %d\n", message, getpid());
    sleep(Tc);
  }

  return 0;
}
