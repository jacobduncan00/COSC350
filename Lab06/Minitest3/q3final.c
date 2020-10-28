#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char *argv[])
{
  if (argc != 2)
  {
    printf("ERROR: Invalid amount of arguments passed, expected 2\n");
    printf("Ex: ./a.out [inputFile]\n");
    exit(1);
  }

  int inputFile;
  inputFile = open(argv[1], O_RDONLY);
  if (inputFile < 0)
  {
    printf("ERROR: Input file error!");
    exit(1);
  }

  int fileParent, fileChild;
  pid_t pid;
  char buf;
  int nr;

  pid = fork();

  switch (pid)
  {
  case -1:
    perror("fork failed");
    exit(1);

  case 0:
    umask(0);
    if ((fileChild = open("child.txt", O_RDWR | O_CREAT, 0666)) < 0)
    {
      printf("ERROR: Cannot open / create child.txt!\n");
      break;
    }

    lseek(inputFile, 0, SEEK_SET);
    while ((nr = read(inputFile, &buf, 1)) > 0)
    {
      write(fileChild, &buf, nr);
    }
    close(fileChild);
    break;

  default:
    umask(0);
    if ((fileParent = open("parent.txt", O_RDWR | O_CREAT, 0666)) < 0)
    {
      printf("ERROR: Cannot open / create parent.txt!\n");
      break;
    }

    lseek(inputFile, 0, SEEK_SET);
    while ((nr = read(inputFile, &buf, 1)) > 0)
    {
      write(fileParent, &buf, nr);
    }
    close(fileParent);
    break;
  }

  close(inputFile);

  return 0;
}
