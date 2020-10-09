#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

void stringreset(char *s);

char *getFileName(char *dir);

int main(int argc, char *argv[])
{
  if (argc != 3)
  {
    printf("ERROR: Expecting 3 arguments (1. Executable name 2. File name 3. Path to directory where file will be moved)\n");
    return 0;
  }

  if (access(argv[1], F_OK) == -1)
  {
    printf("ERROR: cannot access the input file\n");
    return 0;
  }

  struct stat buf;
  stat(argv[2], &buf);

  if (S_ISDIR(buf.st_mode))
  {
    char buf2[PATH_MAX];
    char *fileName = getFileName(argv[1]);
    sprintf(buf2, "%s/%s", argv[2], fileName);
    link(argv[1], buf2);
    unlink(argv[1]);
  }
  else
  {
    link(argv[1], argv[2]);
    unlink(argv[1]);
  }
  return 0;
}

void stringreset(char *s)
{
  int i = 0;
  while (s[i] != '\0')
  {
    s[i] = 0;
    i++;
  }
}

char *getFileName(char *dir)
{
  int i = 0;
  int j = 0;
  char *fileName = malloc(PATH_MAX);
  while (dir[i] != '\0')
  {
    if (dir[i] == '/')
    {
      if (dir[i + 1] == '\0')
      {
        break;
      }
      stringreset(fileName); // reset the string after testing if directory
      j = 0;
    }
    else
    {
      fileName[j] = dir[i];
      j++;
    }
    i++;
  }
  return fileName;
}
