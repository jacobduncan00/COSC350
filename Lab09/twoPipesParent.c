/*
 Jacob Duncan 
 Lab 09
 Task 3
 twoPipesParent.c
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
    int data_processed, dataToWrite;
    int file_pipes[2];
    int pipe2[2];
    const char messageToSend[] = "Hi there, Kiddo";
    char buffer[BUFSIZ + 1];
    pid_t fork_result;

    memset(buffer, '\0', sizeof(buffer));

    if(pipe(file_pipes) == 0 && pipe(pipe2) == 0)
    {
      fork_result = fork();
    	if(fork_result == -1)
    	{
      	fprintf(stderr, "Fork Failure");
      	exit(EXIT_FAILURE);
    	}

    	if(fork_result==0)
    	{
          // Send both file descriptors to the child and the message "Hi there, Kiddo"
          char rBuffer[BUFSIZ + 1];
          char wBuffer[BUFSIZ + 1];
          close(file_pipes[1]);
          close(pipe2[0]);
          sprintf(rBuffer, "%d", file_pipes[0]);
          sprintf(wBuffer, "%d", pipe2[1]);
       		(void)execl("twoPipesChild", "twoPipesChild", rBuffer, wBuffer, (char*)0);
    	    exit(EXIT_FAILURE);
    	}
    	else
    	{
          // Read and print the message from the child
          close(file_pipes[0]);
          close(pipe2[1]);
        	data_processed=write(file_pipes[1], messageToSend, strlen(messageToSend));
          dataToWrite = read(pipe2[0], buffer, 6);
          printf("Parent (%d) sent %d bytes to the child. \n", getpid(), 15);
        	wait(&fork_result);
        	printf("Parent (%d) recieved the message \" %s \" made of %d bytes. \n", getpid(), buffer, dataToWrite);
    	}
  	}
    exit(EXIT_SUCCESS);
}
