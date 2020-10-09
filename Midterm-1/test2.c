#include <unistd.h>
#include <fcntl.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h> // you need for strlen() method

int convIntToStr(char *str, int x);

int convStrToInt(char *str, int x);

int main(int argc, char *argv[])
{
  if (argc != 2)
  {
    printf("ERROR: must pass one argument !\n");
    return 0;
  }
  int inputFile;
  if ((inputFile = open(argv[1], O_RDONLY)) < 0)
  {
    printf("Open %s file error \n", argv[1]);
    return 1;
  }
  int size = lseek(inputFile, 0, SEEK_END);
  lseek(inputFile, 0, SEEK_SET);
  char buf, str[size];
  int curr = 0;

  while ((read(inputFile, &buf, 1)) == 1)
  {
    if (buf >= 48 && buf <= 57)
    {
      str[curr] = buf;
      curr++;
    }
  }
  close(inputFile);
  int num = convStrToInt(str, curr);
  num += 10;
  convIntToStr(str, num);
  write(1, str, curr);
  return 0;
}

int convIntToStr(char *str, int x)
{
  sprintf(str, "%d", x);
  return (strlen(str));
}

int convStrToInt(char *str, int x)
{
  int num = 0;
  for (int i = 0; i < x; i++)
  {
    num = (num * 10) + (str[i] - 48);
  }
  return num;
}
