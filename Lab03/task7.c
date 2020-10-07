//Jacob Duncan
//Sept 29, 2020
//Lab3
//task7.c

#include <stdio.h>
#include <stdlib.h>

extern int errno;

int toString(char str[])
{
  int sign, offset;

  if (str[0] == '-')
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

  int n = 0;

  for (int i = offset; str[i] != '\0'; i++)
  {
    n = n * 10 + str[i] - '0';
  }

  if (sign == -1)
  {
    n = -n;
  }

  return n;
}

int main(int argc, char *argv[])
{
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
