#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
int gValue = 10;

void main()
{
  char *sId;
  int iStack = 20;

  pid_t pID = fork();
  if (pID == 0)
  {
    sId = "Child Process: ";
    gValue++;
    iStack++;
  }
  else if (pID < 0)
  {
    printf("Failed to fork\n");
    exit(1);
  }
  else
  {
    wait(NULL);
    sId = "Parent Process:";
    gValue = gValue + 5;
    iStack = iStack + 5;
  }
  printf("%s\n", sId);
  printf(" Global variable: %d\n", gValue);
  printf(" Stack variable: %d\n", iStack);
}
