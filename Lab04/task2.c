// Jacob Duncan
// October 10, 2020
// lab4
// task2.c

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int str_to_int(char *c)
{
  int a = 0;
  int num = 0;
  while (c[a] != '\0')
  {
    num = 10 * num + (c[a] - '0');
    a++;
  }
  return num;
}

void int_to_str(int fd, char a[])
{
  int ascii = str_to_int(a);
  char toWrite = ascii;
  write(fd, &toWrite, 1);
}

int main(int argc, char *argv[])
{
  int curr = 0;
  char buf1[1], buf2[4];
  if (argc != 2)
  {
    printf("[ERROR] Must pass one argument, the output file of task8 for lab3!\n");
    return 1;
  }
  int inputFile = open(argv[1], O_RDONLY);
  if (inputFile < 0)
  {
    printf("ERROR: Input file error!");
    return 1;
  }
  int outputFile = open("task2output", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP);
  if (outputFile < 0)
  {
    printf("ERROR: Output file error!");
    return 0;
  }
  while (read(inputFile, buf1, 1) > 0)
  {
    if (buf1[0] == ' ') // ' ' == (char)0
    {
      buf2[curr] = '\0';
      int_to_str(outputFile, buf2);
      curr = 0; // reset back to 0
    }
    else if (buf1[0] == '\n') // '\n' == (char)127
    {
      write(outputFile, "\n", 1);
    }
    else
    {
      buf2[curr] = buf1[0];
      curr++;
    }
  }
  return 0;
}
