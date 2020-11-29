/*
 Jacob Duncan
 Lab 10
 Task 1
 msgQsnd.c
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
    buf.type = 1; // Set the message type to 1, must be > 0. Used by the receiving process for message selection
    char *userInput = (char *)calloc(256, sizeof(int));

    puts("Enter two inerger values: ");

    // Reading in 2 integers from the user
    while (fgets(userInput, 256, stdin), !feof(stdin))
    {
        // Converting the input into 2 integers
        sscanf(userInput, "%d%d", &buf.one, &buf.two);
        // Sending the MsgBuffer struct, with our 2 integers, to the message queue
        if (msgsnd(Qid, (MsgBuffer *)&buf, 2 * sizeof(int), 0) == -1)
        {
            perror("ERROR: msgsnd() error!");
        }
        puts("Enter two integer values: ");
    }

    // Removing the message queue, using IPC_RMID to remove the IPC identifier
    if (msgctl(Qid, IPC_RMID, NULL) == -1)
    {
        perror("ERROR: msgctl() error!");
        exit(1);
    }
    return 0;
}
