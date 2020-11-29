#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdbool.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{

  int p1[2], p2[2];

  if (pipe(p1) < 0)
  {
    printf("Could not open p1\n");
  }

  if (pipe(p2) < 0)
  {
    printf("Could not open p2\n");
  }

  pid_t pid = fork();

  if (pid == 0) //child process
  {
    close(p1[0]); // close read
    close(p2[1]); // close write

    char msgToParent[] = "Hi, Mom";

    write(p1[1], msgToParent, 8); //send msg to parent through write pipe
    close(p1[0]);                 // close read

    char buf[11]; // because we know exact size of the message is 11
    if (read(p2[0], buf, 11) > 0)
    {
      printf("My mom said %s\n", buf);
      close(p2[1]);
    }
  }
  else if (pid > 0) //parent process
  {
    close(p1[1]); // close write
    close(p2[0]); // close read

    char buf[8]; // because we know exact size of the message is 8
    if (read(p1[0], buf, 8) > 0)
    {
      printf("My child said %s\n", buf);
      close(p1[0]);
    }

    char msgToChild[] = "I love you\n";

    write(p2[1], msgToChild, 11); //send msg to child
    close(p2[1]);
  }

  return 0;
}
