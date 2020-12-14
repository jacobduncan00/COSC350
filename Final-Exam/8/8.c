#include <sys/types.h>
#include <fcntl.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <signal.h>

int READ_END = 0;
int WRITE_END = 1;

void handler(int sig) {
  if(sig == SIGUSR1) {
    // This is used for synchronization between parent and child
  }
}

int main() {
  umask(0);

  int status;
  int p1[2]; // Pipe for reading and writing

  pipe(p1);

  int fileDescriptor1 = open("foo", O_CREAT | O_RDWR, 0666); // set permissions 
  int fileDescriptor2 = dup(fileDescriptor1);
  pid_t pid = fork(); // Creating process

  signal(SIGUSR1, handler); // Make sure that both the parent and the child have signal handler 

  if(pid == 0) { // Child process
    write(fileDescriptor2, "Hi, Mom", 7); // Child writes to file 
    close(fileDescriptor2);
    kill(getppid(), SIGUSR1); // Signal the parent process
    pause(); // Wait for the message from the parent

    close(p1[WRITE_END]); // close the writing for the pipe, because we are now just reading

    char msg[18];
    if(read(p1[READ_END], msg, 18) > 0) { // Read message that the parent sent
      printf("My Mom said %s\n", msg);
      close(p1[READ_END]);
    }

    return 0;

  } else { // Parent process

    pause(); // make sure we wait for the child process
    lseek(fileDescriptor1, SEEK_SET, 0);
    char readMSG[7];
    read(fileDescriptor1, readMSG, 7);
    printf("My son said %s\n", readMSG);
    close(fileDescriptor1);

    close(p1[READ_END]); // close because we are no longer reading and will now write

    char msgBuf[18] = "what do you want\0";
    write(p1[WRITE_END], msgBuf, 18);
    kill(pid, SIGUSR1); // signal the child process

    close(p1[WRITE_END]);
  }

  return 0;

}


