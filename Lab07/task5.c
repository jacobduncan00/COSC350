/*
 * Jacob Duncan
 * Lab 07
 * Task 5
 * task5.c
 */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>

int main()
{
	sigset_t mask2, mask3, orig_mask;
	
	sigemptyset(&mask2);
	sigemptyset(&mask3);

	sigaddset(&mask2, 2);
	sigaddset(&mask3, 3);

	sigprocmask(SIG_BLOCK, &mask2, &orig_mask);
	sigprocmask(SIG_BLOCK, &mask3, &orig_mask);

	for(int i = 1; i <= 5; i++)
	{
		printf("%d\n", i);
		sleep(1);
	}

	sigprocmask(SIG_UNBLOCK, &mask3, &orig_mask);

	for(int i = 1; i <= 5; i++)
	{
		printf("%d\n", i);
		sleep(1);
	}

	exit(0);
}
