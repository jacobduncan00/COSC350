// Jacob Duncan
// October 8, 2020
// lab4
// task1.c

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

//convert string to integer
int convertStrToInt(char *str, int n);

//convert integer to string
int convertIntToStr(char *str, int x);

// checks if int is a digit in ASCII
int isDigit(int c);

int main(int argc, char *argv[])
{
  if (argc != 2)
  {
    printf("[ERROR] Must pass one argument!\n");
    exit(1);
  }

  int inputFile;
  if ((inputFile = open(argv[1], O_RDONLY)) < 0)
  {
    printf("Open %s file error\n", argv[1]);
    exit(2);
  }

  int size = lseek(inputFile, 0, SEEK_END); // Get size of file
  lseek(inputFile, 0, SEEK_SET);            // Reset offset to beginning

  char buf, str[size];
  int curr = 0;

  while ((read(inputFile, &buf, 1)) == 1)
  {
    if (isDigit(buf)) // if character is a number
    {
      str[curr] = buf;
      curr++;
    }
  }
  close(inputFile);

  int num = convertStrToInt(str, curr);
  num += 10;
  convIntToStr(str, num);
  write(1, str, curr);

  return 0;
}

int convertStrToInt(char *str, int n)
{
  int num = 0;
  for (int i = 0; i < n; i++)
  {
    num = (num * 10) + (str[i] - 48);
  }

  return num;
}

int convIntToStr(char *str, int x)
{
  sprintf(str, "%d", x);
  return (strlen(str));
}

int isDigit(int c)
{
  if (c >= 48 && c <= 57) // if int is an ASCII number
  {
    return -1;
  }
  return 0;
}
