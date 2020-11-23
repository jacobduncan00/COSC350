/*
 Jacob Duncan 
 Lab 09
 Task 3
 twoPipesChild.c
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
  int data_processed, dataToWrite;
  char buffer[BUFSIZ+1];
  int writeFD, readFD;
  char message[] = "Hi Mom";

  memset(buffer, '\0', sizeof(buffer));
  sscanf(argv[1], "%d", &readFD);
  sscanf(argv[2], "%d", &writeFD);

  data_processed = read(readFD, buffer, BUFSIZ);
  dataToWrite = write(writeFD, message, 6);
  printf("Child (%d) recieved the message \" %s \" made of %d bytes. \n", getpid(), buffer, data_processed);
  printf("Child (%d) sent %d bytes to the parent. \n", getpid(), dataToWrite);
  exit(EXIT_SUCCESS);
}
