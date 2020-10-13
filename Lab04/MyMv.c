// Jacob Duncan
// October 12, 2020
// lab4
// MyMv.c

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char *argv[])
{
  if (argc != 3)
  {
    printf("ERROR: Expecting 3 arguments [1. Executable name 2. File name 3. Path to directory where file will be moved]\n");
    return 1;
  }

  if (access(argv[1], F_OK) == -1) // Checking the user permissions for the file passed as argument
  {
    printf("ERROR: cannot access the file passed, therefore cannot move file!\n");
    return 1;
  }

  struct stat buf;
  stat(argv[2], &buf);
  if (S_ISDIR(buf.st_mode)) // if moving to a directory already created
  {
    char path[strlen(argv[1]) + strlen(argv[2])];
    sprintf(path, "%s", argv[2]);
    sprintf(path, "%s/%s", path, argv[1]);
    printf("%s can now be found at: %s \n", argv[1], path);
    link(argv[1], path);
    unlink(argv[1]);
  }
  else // else if moving a to a directory not created
  {
    char path[strlen(argv[1]) + strlen(argv[2])];
    sprintf(path, "%s", argv[2]);
    printf("Creating directory with path: %s \n", path);
    sprintf(path, "%s/%s", path, argv[1]);
    printf("%s can now be found at: %s \n", argv[1], path);
    mkdir(argv[2], 0777);
    link(argv[1], path);
    unlink(argv[1]);
  }
  return 0;
}
