// Write C program which passes input and output file name as command line argument
// Open the input file as read only
// Open the outout file with mode rw-rw-rw.
// The output file should be the reverse order of the input file

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char* argv[]) {

  if (argc < 3) {
    printf("Incorrect amount of arguments, Program should be called like: ./reverse [inputFile] [outputFile]\n");
    return 0;
  }

  int fileDescriptors[2];
  /*umask(0); // Reset the umask of the files*/
  printf("here 1");

  fileDescriptors[0] = open(argv[1], O_RDONLY);
  fileDescriptors[1] = open(argv[2], O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);

  if (fileDescriptors[0] == -1) {
    printf("Could not open input file, terminating program\n");
    return 0;
  }
  printf("here 2");

  int offset = 0;
  char buf[1];

  while(pread(fileDescriptors[0], buf, 1, offset) > 0) {
    offset++; // Getting the size of the file
    printf("%d", offset);
  }

  printf("here");


  while(offset >= 0) {
    if(pread(fileDescriptors[0], buf, 1, offset) > 0) { // Print to file in reverse
      write(fileDescriptors[1], buf, 1);
      offset--;
    }
  }

  close(fileDescriptors[0]);
  close(fileDescriptors[1]);

  return 0;
}
