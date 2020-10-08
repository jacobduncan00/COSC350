#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
  char *path1 = "/mnt/linuxlab/home/jduncan5/Dir1";
  char *path2 = "/mnt/linuxlab/home/jduncan5/Dir2";
  char *path21 = "/mnt/linuxlab/home/jduncan5/Dir2/Dir21";

  if (mkdir(path1, 0777) < 0)
  {
    printf("Error making directory for Dir1");
  }

  if (mkdir(path2, 0777) < 0)
  {
    printf("Error making directory for Dir2");
  }

  if (mkdir(path21, 0777) < 0)
  {
    printf("Error making directory for Dir11");
  }

  char *mainpath = "/mnt/linuxlab/home/jduncan5/hello";
  char *copypath = "/mnt/linuxlab/home/jduncan5/Dir2/Dir21/hello";

  int fd1, fd2;
  if ((fd1 = open(mainpath, O_RDONLY)) < 0)
  {
    printf("ERROR: error reading inputfile, make sure that the file is in your home directory");
    return 0;
  }
  if ((fd2 = open(copypath, O_RDWR | O_CREAT, S_IRUSR | S_IWUSR | S_IXUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH)) < 0)
  {
    printf("ERROR: error reading output file path");
    close(fd1);
    close(fd2);
    return 0;
  }

  char buf;
  int nr;
  while ((nr = read(fd1, buf, 1) > 0))
  {
    write(fd2, buf, nr);
  }
  close(fd1);
  close(fd2);

  if (symlink(path21, "/mnt/linuxlab/home/jduncan5/Dir1/toDir21") < 0)
  {
    printf("ERROR: Symlink error!\n");
  }
  if (symlink(copypath, "/mnt/linuxlab/home/jduncan5/Dir1/toHello") < 0)
  {
    printf("ERROR: Symlink error!\n");
  }
  return 0;
}
