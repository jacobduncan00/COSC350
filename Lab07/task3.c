/*
 * Jacob Duncan
 * Lab 07
 * Task 3
 * task3.c
 */

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

int main(){

	pid_t pid;
	int fd1, fd2;
	char buf;

	pid = fork();
	if (pid < 0) {
		printf("fork failed");
		exit(1);
	} else if (pid == 0) {
		fd2 = open("foo", O_WRONLY|O_CREAT|O_EXCL, 0600);
		if (fd2 < 0) {
			printf("ERROR: Output file cannot be opened or created");
			exit(1);
		}
		char str[] = "Hi Mom";
		write(fd2, &str, 6);
	} else {
		wait(&pid);
		fd1 = open("foo", O_RDONLY);
		if (fd1 < 0) {
			printf("ERROR: Cannot read from foo");
			exit(1);
		}
		printf("My son said ");
		while(read(fd1, &buf, 1) > 0) {
			printf("%c", buf);
		}
		printf("\n");
	}
	close(fd1);
	close(fd2);
	return 0;
}
