/* setenv.c */
#include <stdlib.h>
#include <stdio.h>

int main()
{
  char *env1 = getenv("TEST11");
  printf("TEST11=%s\n", env1); //show current env variable
  setenv("TEST11", "abcd", 1); //reset it
  env1 = getenv("TEST11");
  printf("TEST11=%s\n", env1);
  return 0;
}
