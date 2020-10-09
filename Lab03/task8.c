//Jacob Duncan
//Sept 29, 2020
//Lab3
//task8.c

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
  if (argc != 3)
  {
    printf("ERROR: Argument number not valid. Expecting 2 arguments! [inputFileName, outputFileName]");
    exit(1);
  }
  int inputFile, outputFile, num;
  char buf;

  inputFile = open(argv[1], O_RDONLY);
  if (inputFile < 0)
  {
    printf("ERROR: Input file error!");
    exit(1);
  }

  umask(0); // Have to do this in order to reset the permissions on files
  outputFile = open(argv[2], O_RDWR | O_CREAT | O_EXCL, 0666);
  if (outputFile < 0)
  {
    printf("ERROR: Output file error!");
    exit(1);
  }
  if (inputFile > 0 && outputFile > 0)
  {
    dup2(outputFile, 1);
    while ((num = read(inputFile, &buf, 1)) > 0)
    {
      if ((int)buf == 10)
      {
        printf("\n");
      }
      else if (buf == ' ')
      {
        printf("%d ", (int)buf); // this should be 32
      }
      else if (buf != ' ')
      {
        num = (int)buf;
        printf("%d ", num);
      }
    }
  }
  else
  {
    printf("ERROR: Error reading input and/or output file!");
  }
  close(inputFile);
  close(outputFile);
  exit(0);
}
