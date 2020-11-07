#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

int main()
{
  pid_t pid, endpid;
  int i, j;
  int status;
  pid = fork();
  if (pid < 0)
  {

    printf("Error making child");
    exit(1);
  }
  // child
  if (pid == 0)
  {
    pid = fork();
    if (pid < 0)
    {

      printf("Error making child");
      exit(1);
    }

    if (pid > 0)
    {
      for (i = 0; i < 101; i++)
      {
        printf("I am your child");
        sleep(1);
      }

      exit(0);
    }
    else
    { // grandchild run into its parent finished

      pid = wait(&status);

      while (1)
      {
        printf("I am your grandchild");
        sleep(1);
        if (WIFEXITED(status))
        { // child finished  now grandchild terminates
          break;
        }
      }

      exit(0);
    }
  }
  else
  { // parent process

    while (1)
    {
      endpid = waitpid(pid, &status, WNOHANG | WUNTRACED);

      if (endpid == 0)
      {
        printf("I am your parent");
        sleep(1);
      }
      else
      {
        break;
      }
    }

    printf("I finish my job");
    exit(0);
  }

  exit(0);

} // close bracket for end of program
