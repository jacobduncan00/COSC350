#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main()
{
  int inputFile, outputFile, fooBytes;
  char buf[32];

  // Open file foo
  inputFile = open("foo", O_RDONLY);
  if (inputFile < 0)
  {
    puts("FOO ERROR: Input file error.");
    exit(1);
  }

  umask(0);                                                     // Have to do this in order for the rwx-rwx--- to work on the next line, not sure why
  outputFile = open("clone2", O_RDWR | O_CREAT | O_EXCL, 0770); // 0770 stands for read, write, executable permissions on user and group
  if (outputFile < 0)
  {
    puts("CLONE1 ERROR: Output file error.");
    exit(1);
  }

  // Read from foo 32 bytes at a time and write 32 bytes to clone2
  while ((fooBytes = read(inputFile, &buf, 32)) > 0)
  {
    write(outputFile, &buf, fooBytes);
  }

  close(inputFile);
  close(outputFile);
  exit(0);
}
