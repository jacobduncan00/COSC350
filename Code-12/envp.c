/* envp.c display environment strings
with corresponding address */

#include <stdio.h>

int main(int argc, char *argv[], char *envp[])
{
  char **p = envp;
  while (*p != NULL)
  {
    printf("%s (%p)\n", *p, *p);
    *p++;
  }
  return 0;
}
