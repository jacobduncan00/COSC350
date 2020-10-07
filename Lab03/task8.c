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
  dup2(outputFile, 1);
  while (read(inputFile, &buf, 1) == 1)
  {
    num = (int)buf;
    printf("%d ", num); // need space here in order to space out the ascii numbers in the output file
  }
  printf("");
  close(inputFile);
  close(outputFile);
  exit(0);
}
