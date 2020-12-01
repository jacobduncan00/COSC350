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

void handleEnd() {
    printf("Terminating");
}

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

    puts("Enter two integer values: ");

    while(1) {
        fgets(userInput, 256, stdin);
        if (feof(stdin)) {
            printf("EOF");
            buf.one = -1;
            buf.two = -1;
            // Removing the message queue, using msgctl to remove the IPC identifier
            if (msgsnd(Qid, (MsgBuffer *)&buf, 2 * sizeof(int), 0) == -1)
            {
                perror("ERROR: msgsnd() error!");
            }
            printf("SENDING EOF TO msgQrcv.c\n");
            if (msgctl(Qid, IPC_RMID, NULL) == -1)
            {
                perror("ERROR: msgctl() error!");
                exit(1);
            }
            return 0;
        }
        // Converting the input into 2 integers
        sscanf(userInput, "%d%d", &buf.one, &buf.two);
        // printf("%d == %d", buf.one, buf.two);
        if (buf.two == -10) {
            printf("You only inserted 1 value!\n");
        }
        // Sending the MsgBuffer struct, with our 2 integers, to the message queue
        else if (msgsnd(Qid, (MsgBuffer *)&buf, 2 * sizeof(int), 0) == -1)
        {
            perror("ERROR: msgsnd() error!");
        }
        buf.one = -10; // Clear buffer with custom value
        buf.two = -10; // Clear buffer with custom value
        puts("Enter two integer values: ");
    }

    return 0;
}
