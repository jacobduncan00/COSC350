/*
 * Jacob Duncan
 * Lab07
 * Task 1
 * task1.c
 */

#include <sys/types.h>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

static int alarm_fired = 0;

void ding(int sig)
{
	alarm_fired = 1;
}

int main()
{
	pid_t pid;
	printf("alarm application starting\n");
	pid = fork();
	switch(pid) {
		case -1:
			perror("fork failed");
			exit(1);
		case 0:
			sleep(5);
			kill(getppid(), SIGALRM);
			exit(0);
	}

	printf("waiting for alarm to go off\n");
	struct sigaction act;
	memset(&act, 0, sizeof(act));
	act.sa_handler = ding;
	if (sigaction(SIGALRM, &act, 0)) {
		perror("sigaction error");
		return 1;
	}
	pause();
	if (alarm_fired) {
		printf("Ding!\n");
	}
	printf("done\n");
	exit(0);
}
