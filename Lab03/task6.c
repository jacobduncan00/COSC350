//Jacob Duncan
//Sept 29, 2020
//Lab3
//task6.c

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main()
{
  int inputFile, outputFile, bytes;
  char buf;

  // Open file 1
  inputFile = open("foo", O_RDONLY);
  if (inputFile < 0)
  {
    puts("FOO ERROR: Input file error.");
    exit(1);
  }

  umask(0);                                                     // Have to do this in order for the rwx-rwx--- to work on the next line, not sure why
  outputFile = open("foorev", O_RDWR | O_CREAT | O_EXCL, 0760); // 0760 stands for read, write, executable permissions on user and read, write permissions on group
  if (outputFile < 0)
  {
    puts("FOOREV ERROR: Output file error.");
    exit(1);
  }

  while ((read(inputFile, &buf, 1) == 1))
  {
    bytes++;
  }

  while (bytes > 0)
  {
    pread(inputFile, &buf, 1, bytes - 1);
    write(outputFile, &buf, 1);
    bytes--;
  }

  close(inputFile);
  close(outputFile);
  exit(0);
}
