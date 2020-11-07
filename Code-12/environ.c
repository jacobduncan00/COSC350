/* environ.c */
#include <stdio.h>
#include <unistd.h>

extern char **environ;

int main(int argc, char *argv[])
{
  char **p = environ;
  while (*p != NULL)
  {
    printf("%s (%p)\n", *p, *p);
    *p++;
  }
  return 0;
}
