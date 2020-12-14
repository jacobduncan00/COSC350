#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/msg.h>

#define MAX_SIZE 255

struct msgbuf {
	long type;
	char text[MAX_SIZE];
};

int main() {
	key_t key = ftok("process1.c", 'B');
	int fileDescriptor = open("HALF_DUPLEX", 0666);

	int Qid = msgget(key, 0644 | IPC_CREAT);

	struct msgbuf buffer;
	while(1) {
		// Get the message from the buffer
		msgrcv(Qid, (struct msgbuffer*) &buffer, MAX_SIZE * sizeof(char), 0, 0);
		printf("%s", buffer.text); // Print what was recieved in the buffer

		char returnMsg[] = "I got it";
		write(fileDescriptor, returnMsg, MAX_SIZE);
	}
}
