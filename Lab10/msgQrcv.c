/*
 Jacob Duncan
 Lab 10
 Task 1
 msgQrcv.c
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/msg.h>

typedef struct MSGBUF
{
  long type;
  int one;
  int two;
} MsgBuffer;

int main(int argc, char *argv[])
{
  // Sets key value to msgQsnd.c
  key_t key;
  if ((key = ftok("msgQsnd.c", 'B')) == -1)
  {
    perror("ERROR: ftok() error!");
    exit(1);
  }

  // Creates the message queue with the key and the privileges rw-r--r-- (0644)
  // IPC_CREAT creates entry if key does not exist
  int Qid;
  if ((Qid = msgget(key, 0644 | IPC_CREAT)) == -1)
  {
    perror("ERROR: msgget() error!");
    exit(1);
  }

  MsgBuffer buf;
  while (1)
  {
    // Reads the message from the buffer and store into MsgBuffer object
    if (msgrcv(Qid, (MsgBuffer *)&buf, 2 * sizeof(int), 0, 0) == -1)
    {
      perror("ERROR: msgrcv() error!");
      exit(1);
    }

    printf("The sum of the digits recieved from [msgQsnd.c] is %d \n", buf.one + buf.two);
  }

  return 0;
}
