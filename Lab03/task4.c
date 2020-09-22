#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main()
{
  int inputFile1, inputFile2, outputFile, offset;
  char buf;

  // Open file 1
  inputFile1 = open("foo", O_RDONLY);
  if (inputFile1 < 0)
  {
    puts("FOO ERROR: Input file error.");
    exit(1);
  }

  // Open file 2
  inputFile2 = open("foo1", O_RDONLY);
  if (inputFile2 < 0)
  {
    puts("FOO1 ERROR: Input file error.");
    exit(1);
  }

  umask(0);                                                    // Have to do this in order for the rwx-rwx--- to work on the next line, not sure why
  outputFile = open("foo12", O_RDWR | O_CREAT | O_EXCL, 0760); // 0760 stands for read, write, executable permissions on user and read, write permissions on group
  if (outputFile < 0)
  {
    puts("FOO12 ERROR: Output file error.");
    exit(1);
  }

  // Write the first input file to the output file
  while ((read(inputFile1, &buf, 1) == 1))
    write(outputFile, &buf, 1);

  // Seek to get to put the offset at the end of the output file
  if ((offset = lseek(outputFile, 0, SEEK_END)) == -1)
  {
    printf("Cannot seek output file foo12. \n");
  }
  else
  {
    // Write the second input file to the output file at the new offset
    while ((read(inputFile2, &buf, 1) == 1))
      write(outputFile, &buf, 1);
  }

  close(inputFile1);
  close(inputFile2);
  close(outputFile);
  exit(0);
}
