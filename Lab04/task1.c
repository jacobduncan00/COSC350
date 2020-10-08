//Jacob Duncan
//Sept 29, 2020
//lab4
//task1.c

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

//convert string to integer
int convertToInt(char *str, int n);

//convert integer to string
int convertToStr(char *str, int x);

int main(int argc, char *argv[])
{
  if (argc != 2)
  {
    printf("[ERROR] Must pass one argument!\n");
    exit(1);
  }

  int fd; //file descriptor

  //open given file for read only
  if ((fd = open(argv[1], O_RDONLY)) < 0)
  {
    printf("Open %s file error\n", argv[1]);
    exit(2);
  }

  int size = lseek(fd, 0, SEEK_END);
  lseek(fd, 0, SEEK_SET);

  char buf, str[size];
  int i = 0;

  while ((read(fd, &buf, 1)) == 1)
  {
    if (buf >= '0' && buf <= '9') //if character read ranges 0-9 add to str
    {
      str[i] = buf;
      i++;
    }
  }
  close(fd);

  int newSize = i;
  char str2[newSize];

  int x = convertToInt(str, newSize); //convert to int

  x += 10; //add 10

  convertToStr(str2, x); //convert to string

  write(1, str2, i); //write to console
  printf("\n");

  return 0;
}

int convertToInt(char *str, int n)
{
  int num = 0;
  for (int i = 0; i < n; i++)
  {
    num = num * 10 + str[i] - '0';
  }

  return num;
}

int convertToStr(char *str, int x)
{
  sprintf(str, "%d", x);
  return (strlen(str));
}
