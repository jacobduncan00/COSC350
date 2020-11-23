/*
 Jacob Duncan 
 Lab 09
 Task 2
 pipe4.c
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
  int data_processed;
  char buffer[BUFSIZ+1];
  int file_descriptor;

  memset(buffer, '\0', sizeof(buffer));
  sscanf(argv[1], "%d", &file_descriptor);
  data_processed=read(file_descriptor, buffer,BUFSIZ);
  close(file_descriptor);
  printf("%d - read %d bytes: %s\n", getpid(), data_processed, buffer);
  exit(EXIT_SUCCESS);
}
