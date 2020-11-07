/* getenv.c */
#include <stdlib.h>
#include <stdio.h>

int main()
{
  printf("HOME=%s\n", getenv("HOME"));
  printf("PATH=%s\n", getenv("PATH"));
  printf("ROOTPATH=%s\n", getenv("ROOTPATH"));
  return 0;
}
