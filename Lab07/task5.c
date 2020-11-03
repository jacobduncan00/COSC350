/* Jacob Duncan
 * Lab 07
 * Task 5
 * task5.c
 *    
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>

 int main()
{
		sigset_t mask, mask2, orig_mask;
			
		sigemptyset(&mask); // clear signal set
		sigemptyset(&mask2); // clear signal set

		sigaddset(&mask, 2); 
		sigaddset(&mask2, 3);

		sigprocmask(SIG_BLOCK, &mask, &orig_mask); // add blocking for mask
		sigprocmask(SIG_BLOCK, &mask2, &orig_mask); // add blocking for mask2

		for(int i = 1; i <= 5; i++) // loop 5 print and wait 5 seconds
		{
			printf("%d\n", i);
			sleep(1);
		}

		sigprocmask(SIG_UNBLOCK, &mask2, &orig_mask); // unblock mask2

		for(int i = 1; i <= 5; i++) // loop 5 print and wait 5 seconds
		{
			printf("%d\n", i);
			sleep(1);
		}

		exit(0);
}
