/*
 Jacob Duncan 
 Lab 09
 Task 4
 pipeFifo.c
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>

#define fifo_name "/tmp/task4_fifo"

const int READ_END = 0;
const int WRITE_END = 1;

int main(int argc, char* argv[])
{
    int fifo, fd;
    int data_processed;
    const char some_data[] = "123";
    char* buffer = malloc(3 * sizeof(char));

    memset(buffer, '\0', 3);
    fifo = mkfifo(fifo_name, 0777);
    fd = open(fifo_name, O_RDWR);
    data_processed = write(fd, some_data, strlen(some_data));
    printf("Wrote %d bytes. \n", data_processed);
    data_processed = read(fd, buffer, 3);
    printf("Read %d bytes: %s \n", data_processed, buffer);
    free(buffer);
    exit(EXIT_SUCCESS);
}
