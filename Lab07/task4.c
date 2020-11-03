/*
 * Jacob Duncan
 * Lab 07
 * Task 4
 * task4.c
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

void handler(int sig){

	if(sig == SIGUSR1) {

		printf("Hi Honey, Anything wrong?\n");

	} else if (sig == SIGUSR2) {

		printf("Do you make trouble again?\n");
	}

}

int main() {

	struct sigaction catch;
	catch.sa_handler = handler;
	sigemptyset(&catch.sa_mask);
	catch.sa_flags = 0;

	int status;
	int childKill;
	pid_t pid1 = fork();
	pid_t pid2;

	if (pid1 < 0) {
		printf("fork failed");
		exit(1);
	} else if(pid1 == 0){ // First Child

		kill(getppid(), SIGUSR1); 
		exit(0);

	} else {
		pid2 = fork();

		if (pid2 < 0) {
		printf("fork failed");
		exit(1);
		} else if(pid2 == 0){ // Second Child

			childKill = waitpid(pid1, &status, WUNTRACED);
			kill(getppid(), SIGUSR2); 
			exit(0);

		} else { // Parent

			sigaction(SIGUSR1, &catch, NULL); 
			pause();

			sigaction(SIGUSR2, &catch, NULL);
			pause();
			exit(0);

		}
	}

	return 0;

}

