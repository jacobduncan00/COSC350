#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdbool.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

//better to declare ends of the pipe than to try to remember 0 or 1
int READ_END = 0;
int WRITE_END = 1;

int main()
{

  //since we are sending data child --> parent
  //then later parent --> child
  //we need two pipes
  //not all linux systems support bi-directional pipes
  int pipe1[2], pipe2[2];

  //i know we do not have to error check, i only if statements did this for debugging
  if (pipe(pipe1) < 0)
  {
    printf("Could not open pipe1\n");
  }

  if (pipe(pipe2) < 0)
  {
    printf("Could not open pipe2\n");
  }

  pid_t pid = fork();

  if (pid == 0)
  { //child process

    //Close the input pipe1/output pipe2 from the child's side.
    close(pipe1[READ_END]);
    close(pipe2[WRITE_END]);

    char msg1[] = "Hi, Mom";

    write(pipe1[WRITE_END], msg1, 8); //send msg to parent through pipe
    close(pipe1[READ_END]);

    char buf[11];
    if (read(pipe2[READ_END], buf, 11) > 0)
    { //read message from parent
      printf("My mom said %s\n", buf);
      close(pipe2[WRITE_END]);
    }
  }
  else if (pid > 0)
  { //parent process

    //Close the input pipe from the parent's side/output of second pipe
    close(pipe1[WRITE_END]);
    close(pipe2[READ_END]);

    char buf[8];
    if (read(pipe1[READ_END], buf, 8) > 0)
    { //read message from child
      printf("My child said %s\n", buf);
      close(pipe1[READ_END]);
    }

    char msg2[] = "I love you\n";

    write(pipe2[WRITE_END], msg2, 11); //send msg to child through pipe2
    close(pipe2[WRITE_END]);
  }

  return 0;
}
