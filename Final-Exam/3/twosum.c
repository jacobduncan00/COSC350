#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {
  FILE *pipe_fp;
  char buf[256];
  int fd[2];
  int size;
  char setLine[256], readLine[256];

  pid_t pid = fork();

  if (pid == 0) { // child process

    if (( pipe_fp = popen("./anyinput", "r")) == NULL)
    {
        perror("popen");
        exit(1);
    }
    while (fgets(buf, 256, pipe_fp) != NULL) {
        write(fd[1], setLine, 256); 
    }

  } else { // parent process



  }

  return 0;

}


