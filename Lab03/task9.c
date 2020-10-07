//Jacob Duncan
//Sept 29, 2020
//Lab3
//task9.c

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int palind(int fd1, int fd2)
{
  char buf1, buf2;
  int fileSize = lseek(fd2, -2, SEEK_END);
  for (int i = 0; i < fileSize; i++) // Start with the end of the file and compare it to the beginning of the file
  {
    lseek(fd1, i, SEEK_SET);
    read(fd1, &buf1, 1);
    lseek(fd2, -2 - i, SEEK_END);
    read(fd2, &buf2, 1);

    if (buf1 != buf2)
      return 0;
  }
  return 1;
}

int main(int argc, char *argv[])
{
  if (argc != 2)
  {
    printf("ERROR: Argument number not valid. Expecting 1 argument! [Ex: ./a.out fileName]");
    exit(1);
  }
  int inputFile, inputFileCopy, checker;

  // Open file with name passed as argument 1 in read only mode
  inputFile = open(argv[1], O_RDONLY);
  if (inputFile < 0 || inputFileCopy < 0)
  {
    printf("ERROR: Input file error.");
    exit(1);
  }
  inputFileCopy = dup(inputFile);

  // Checks the file to see if it is a palindrome file, if it is, 1 is returned
  checker = palind(inputFile, inputFileCopy);
  if (checker == 1)
    printf("The file is a palindrome.");
  else
    printf("The file is not a palindrome.");

  close(inputFile);
  close(inputFileCopy);
  exit(0);
}
