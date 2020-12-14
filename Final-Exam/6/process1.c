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
	int fileDescriptor = mkfifo("HALF_DUPLEX", 0666); // Creating the fifo with rw-rw-rw

	// Create the buffer in which we send over the message queue
	struct msgbuf buffer; 
	buffer.type = 1;
	char* userInput = (char*) calloc(MAX_SIZE, sizeof(char)); // Using our max size of 255 for message buffer

	int Qid = msgget(key, 0644 | IPC_CREAT);
	printf("Enter message: ");
	while(fgets(userInput, 255, stdin), !feof(stdin)) {
		int lengthOfString = strlen(userInput);
		strcpy(buffer.text, userInput); // setting the buffer.text to be userInput
		msgsnd(Qid, (struct msgbuffer*) &buffer, MAX_SIZE * sizeof(char), 0);

		char getLine[MAX_SIZE];
		while ((lengthOfString = read(fileDescriptor, getLine, MAX_SIZE)) > 0) {
			printf("Message recieved from process2: %s", getLine);
		}
	}

	// After we get EOF, we need to remove the message queue
	msgctl(Qid, IPC_RMID, NULL);
	return 0;

