/*
 * Jacob Duncan
 * Lab 08
 * Task 1
 * task1.c
 *
 */

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

void *calculateSum(void *n) {
	int i;
	int sum = (int)n;
	for (i = sum - 1; i > 0; i--) {
		sum += i;
	}
	n = (void *)sum;
	return n;
}

void *calculateFactorial(void *n) {
	int i;
	int product = (int)n;
	for (i = product - 1; i > 0; i--) {
		product *= i;
	}
	n = (void *)product;
	return n;
}

int str_to_int(char* str) {
	int n = 0;
	int i = 0;
	while(str[i] != '\0') {
		n = (n * 10) + (str[i] - 48);
		i++;
	}
	return n;
}

int main(int argc, char* argv[]) {
	pthread_t sumThread, factThread;
	int code;

	if (argc != 2) {
		printf("ERROR: Expected 2 arguments and only got %i!\n", argc);
		exit(1);
	}

	int num = str_to_int(argv[1]);

	code = pthread_create(&sumThread, NULL, calculateSum, (void *)num);
	if (code) {
		printf("ERROR: Error occured during creation of pthread");
		exit(-1);
	}

	code = pthread_create(&factThread, NULL, calculateFactorial, (void *)num);
	if (code) {
		printf("ERROR: Error occured during creation of pthread");
		exit(-1);
	}

	void* sum;
	void* fact;

	pthread_join(sumThread, &sum);
	pthread_join(factThread, &fact);

	printf("Sum of arguments: %d\n", (int)sum);
	printf("Factorial of arguments: %d\n", (int)fact);

	pthread_exit(NULL);
	exit(0);

}
