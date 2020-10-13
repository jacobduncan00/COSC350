// Jacob Duncan
// October 10, 2020
// lab4
// task3-1.c

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{

  char *path_to_dir1 = "/mnt/linuxlab/home/jduncan5/Dir1";
  char *path_to_dir2 = "/mnt/linuxlab/home/jduncan5/Dir2";
  char *path_to_dir21 = "/mnt/linuxlab/home/jduncan5/Dir2/Dir21";

  if (mkdir(path_to_dir1, 0777) < 0)
  {
    printf("ERROR: Error making directory for Dir1");
  }

  if (mkdir(path_to_dir2, 0777) < 0)
  {
    printf("ERROR: Error making directory for Dir2");
  }

  if (mkdir(path_to_dir21, 0777) < 0)
  {
    printf("ERROR: Error making directory for Dir21");
  }

  char *mainpath = "/mnt/linuxlab/home/jduncan5/hello";
  char *copypath = "/mnt/linuxlab/home/jduncan5/Dir2/Dir21/hello";

  int inputFile, outputFile;

  if ((inputFile = open(mainpath, O_RDONLY)) < 0)
  {
    printf("ERROR: error reading inputfile, make sure that the file is in your home directory");
    return 0;
  }

  if ((outputFile = open(copypath, O_RDWR | O_CREAT, S_IRUSR | S_IWUSR | S_IXUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH)) < 0)
  {
    printf("ERROR: error reading output file path");
    close(inputFile);
    close(outputFile);
    return 0;
  }

  char buf;
  int bytesRead;

  while ((bytesRead = read(inputFile, buf, 1) > 0))
  {
    write(outputFile, buf, bytesRead);
  }

  close(inputFile);
  close(outputFile);

  if (symlink(path_to_dir21, "/mnt/linuxlab/home/jduncan5/Dir1/toDir21") < 0)
  {
    printf("ERROR: Symlink error!\n");
  }

  if (symlink(copypath, "/mnt/linuxlab/home/jduncan5/Dir1/toHello") < 0)
  {
    printf("ERROR: Symlink error!\n");
  }

  return 0;
}
