#include <stdio.h>
#include <stdlib.h>

extern int errno;

int toString(char a[])
{
  int c, sign, offset, n;

  if (a[0] == '-')
  { // Handle negative integers
    sign = -1;
  }

  if (sign == -1)
  { // Set starting position to convert
    offset = 1;
  }
  else
  {
    offset = 0;
  }

  n = 0;

  for (c = offset; a[c] != '\0'; c++)
  {
    n = n * 10 + a[c] - '0';
  }

  if (sign == -1)
  {
    n = -n;
  }

  return n;
}

int main(int argc, char *argv[])
{
  // Need to somehow check if arguments are number c-strings, not actual strings
  if (argc == 1)
  {
    printf("[ERROR NO.%d] There is not at least one integer on the command line.\n", errno);
    exit(errno);
  }
  int convertedNumberArr[argc];

  for (int i = 1; i < argc; i++)
  {
    convertedNumberArr[i] = toString(argv[i]);
  }

  int sum = 0;
  for (int j = 1; j < argc; j++)
  {
    sum += convertedNumberArr[j];
  }

  printf("Sum: %d\n", sum);
  exit(0);
}
