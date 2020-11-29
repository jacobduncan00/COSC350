#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAXLINESIZE 256

int main()
{
  int numRead, num1, num2, size, CHILD[2], PARENT[2];
  char setLine[MAXLINESIZE], readLine[MAXLINESIZE];
  pid_t pid;
  pipe(CHILD);
  pipe(PARENT);
  pid = fork();

  if (pid > 0) // Parent Process
  {
    close(PARENT[1]); // closed writing
    close(CHILD[0]);  // closed reading
    write(1, "Enter 2 integers: ", 18);
    while ((size = read(STDIN_FILENO, setLine, MAXLINESIZE)) > 0)
    {
      write(CHILD[1], setLine, size);
      numRead = read(PARENT[0], readLine, MAXLINESIZE);
      write(STDOUT_FILENO, readLine, numRead);
    }
  }
  else // Child Process
  {
    close(PARENT[0]); // closed reading
    close(CHILD[1]);  // closed writing
    while ((numRead = read(CHILD[0], readLine, MAXLINESIZE)) > 0)
    {
      if (sscanf(readLine, "%d%d", &num1, &num2) == 2)
      {
        sprintf(readLine, "%d\n", num1 * num2);
        write(PARENT[1], readLine, MAXLINESIZE);
      }
    }
  }
  exit(0);
}
