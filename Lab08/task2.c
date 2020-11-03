/*
 * Jacob Duncan
 * Lab 08
 * Task 2
 * task2.c
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <pthread.h>

void readInScores(int* scores) {
	int score;
	int i, j, n;
	int validScore = 1;

	for (i = 0; i < 20 && validScore; i++) {
		printf("Enter test score %d: ", i + 1);
		scanf("%d", &score);
		while (score < -1) {
			printf("ERROR: You input invalid score! Input a positive score");
			scanf("%d", &score);
		}
		scores[i] = score;
		if (score == -1) {
			validScore = 0;
		} 
	}
	i--;
	for(j = 0; j < i - 1; j++) {
		int minScore = j;
		for (n = j + 1; n < i; n++) {
			if (scores[n] < scores[minScore]) {
				minScore = n;
			}
		}
		// Perform swap
		int holder = scores[j];
		scores[j] = scores[minScore];
		scores[minScore] = holder;
	}
	pthread_exit(NULL);
}

void calculateAverageAndMedium(int* scores) {
	int i;
	int totalOfValidScores = 0;
	float average, medium;

	for (i = 0; scores[i] != -1; i++) {
		totalOfValidScores += scores[i];
	}

	if (i == 0) {
		printf("Scores array is empty therefore, average and medium are both 0");
		pthread_exit(NULL);
	}

	// Calculate Average
	average = (float)totalOfValidScores / i;

	// Calculate Medium
	if (i % 2 != 0) { // If number is odd
		int rhs = (i/2)-1;
		int lhs = (i/2);
		medium = (float)(scores[rhs] + scores[lhs]) / 2; // Gets median value of scores
	} else { // If number is even, easy to get median 
		medium = scores[i/2];
	}

	printf("Average score: %2.2f \t\t Median score: %2.2f\n", average, medium);
	pthread_exit(NULL);
}

void calculateMinAndMax(int* scores) {
	int i;
	int maxScore;

	int minScore = scores[0];

	// This assumes they are already sorted!!!
	for (i = 0; scores[i] != -1; i++) {
		maxScore = scores[i];
	}

	if (i == 0) {
		printf("Scores array is empty, cannot calculate highest and lowest as there are no scores!");
		pthread_exit(NULL);
	}

	printf("Lowest score: %d \t\t Highest score: %d\n", minScore, maxScore);
	pthread_exit(NULL);
}

void clearBuffer(int* scores) {
	int i;

	printf("CLEARING BUFFER ");
	for(i = 0; i < 20; i++) {
		scores[i] = 0;
		printf("%d ", scores[i]);
	}
	printf("\n");
	pthread_exit(NULL);
}

int main(int argc, char* argv[]) {
	pthread_t T[4];
	int code;
	int i;

	int* scores = malloc(20 * sizeof(int)); // Creates array of 20 integers

	code = pthread_create(&T[0], NULL, readInScores, (void *)scores);
	if (code) { 
		printf("ERROR: Cannot create thread to read in scores");
		exit(-1);
	}

	pthread_join(T[0], NULL);

	code = pthread_create(&T[1], NULL, calculateAverageAndMedium, (void *)scores);
	if (code) { 
		printf("ERROR: Cannot create thread to calculate average and median scores");
		exit(-1);
	}

	code = pthread_create(&T[2], NULL, calculateMinAndMax, (void *)scores);
	if (code) { 
		printf("ERROR: Cannot create thread to calculate min and max scores");
		exit(-1);
	}

	pthread_join(T[1], NULL);
	pthread_join(T[2], NULL);

	code = pthread_create(&T[3], NULL, clearBuffer, (void *)scores);
	if (code) { 
		printf("ERROR: Cannot create thread to clear the buffer");
		exit(-1);
	}

	pthread_join(T[3], NULL);
	pthread_exit(NULL);
	return 0;

}
