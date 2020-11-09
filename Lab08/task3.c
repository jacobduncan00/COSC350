/*
 * Jacob Duncan
 * Lab 08
 * Task 3
 * task3.c
 */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#define MAXLINESIZE 256

int main()
{
  int length, size, inputNum1, inputNum2;
  int fd[2]; // Reading and writing file descriptors for both processes
  pid_t pid;
  char setLine[MAXLINESIZE], readLine[MAXLINESIZE];

  if (pipe(fd) < 0)
  {
    printf("ERROR: Pipe error\n");
    exit(1);
  }

  if ((pid = fork()) < 0) // Error
  {
    printf("ERROR: Fork failed\n");
    exit(1);
  }
  else if (pid > 0) // Parent Process
  {
    close(fd[0]); // Close the input pipe for the parent process

    printf("Enter two integers: ");

    while ((size = read(STDIN_FILENO, setLine, MAXLINESIZE)) > 0)
    {
      write(fd[1], setLine, size);

      printf("Enter two more integers: ");
    }
  }
  else // Child Process
  {
    close(fd[1]);

    while ((length = read(fd[0], readLine, MAXLINESIZE)) > 0)
    {
      if (sscanf(readLine, "%d%d", &inputNum1, &inputNum2) == 2) // Get the 2 numbers from the String passed by parent
      {
        sprintf(readLine, "The sum is %d\n", inputNum1 + inputNum2); // Print the sum of the two numbers

        length = strlen(readLine);

        if (write(STDOUT_FILENO, readLine, length) != length)
        {
          printf("ERROR: Writing to standard output error");
          exit(1);
        }
      }
      else // The string passed did not contain exactly 2 integers
      {
        if (write(STDOUT_FILENO, "Invalid input! You must enter two integers.\n", 40) != 40)
        {
          printf("ERROR: Writing to standard output error");
          exit(1);
        }
      }
    }
  }
  return 0;
}
