/*race.c : shows example of race condition*/
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>

static void charatatime(char *);

int main()
{
  pid_t pid;
  if ((pid = fork()) < 0) /* create a child and check for error */
  {
    printf("fork error");
    exit(1);
  }
  /* a child and parent call same function */
  if (pid == 0) // If child
  {
    charatatime("output from child\n");
  }
  else
  {
    charatatime("output from parent\n");
  }
  exit(0);
}
static void charatatime(char *str)
{
  char *ptr; /* child and parent has its own buffer but using same stdout */
  int c;
  setbuf(stdout, NULL); /*set unbuffered */
  for (ptr = str; c = *ptr++;)
    putc(c, stdout);
}
