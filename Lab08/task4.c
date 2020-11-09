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

int main(int argc, char *argv[])
{
  int i;
  int size = 0;
  char *commandToExecute;

  for (i = 1; i < argc; i++) // Start at second command line argument (first is filename)
  {
    size += strlen(argv[i]); // Get length of c-strings in argv
  }

  commandToExecute = calloc(size, sizeof(char)); // dynamically allocate memory for these strings

  for (i = 1; i < argc; i++)
  {
    sprintf(commandToExecute, "%s %s", commandToExecute, argv[i]);
  }

  char buf[BUFSIZ];
  FILE *filePtr;

  if ((filePtr = popen(commandToExecute, "r")) != NULL)
  {
    while (fgets(buf, BUFSIZ, filePtr) != NULL)
    {
      (void)printf("%s", buf);
    }
  }

  pclose(filePtr);

  return 0;
}
