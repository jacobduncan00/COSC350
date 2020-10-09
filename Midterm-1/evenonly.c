#include <stdio.h>
#include <stdlib.h>

int st_to_int(char *c);

int main(int argc, char *argv[])
{
  if (argc <= 1)
  {
    printf("You need to enter numbers !");
    return 0;
  }
  int in[argc];
  for (int i = 1; i < argc; i++)
  {
    in[i] = st_to_int(argv[i]);
  }
  int sum = 0;
  for (int j = 1; j < argc; j++)
  {
    int curr = in[j];
    if (curr % 2 == 0)
    {
      sum += curr;
    }
  }
  printf("The sum of even arguments is %d\n", sum);
}

int st_to_int(char *c)
{
  int index = 0;
  int num = 0;
  while (c[index] != '\0')
  {
    num = (num * 10) + (c[index] - 48);
    index++;
  }
  return num;
}
