#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main()
{
  int inputFile, outputFile, offset, i;
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

  // Seek to get to put the offset at the end of the output file
  offset = lseek(inputFile, 0, SEEK_END);
  if (offset == -1)
  {
    printf("Cannot seek output file foo12. \n");
    exit(1);
  }

  for (i = 1; i <= offset; i++)
  {
    if ((lseek(inputFile, -i, SEEK_END)) == -1) //will get the position -i from the end of the input file
    {
      printf("error");
    }
    read(inputFile, &buf, 1);            // read byte by byte
    int wr = write(outputFile, &buf, 1); // write byte by byte
    if (wr == 0)                         // So we don't get the offset indexing error
    {
      return -1;
    }
  }

  close(inputFile);
  close(outputFile);
  exit(0);
}
