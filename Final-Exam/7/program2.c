#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>


#define SIZE 10
typedef int semaphore;
semaphore mutex = 0;
semaphore empty = 2;
semaphore full = 1;

union semun {
  int val;
  struct semid_ds *buf;
  unsigned short *array;
};

void up(int i, int semid) {
  struct sembuf up = {i, 1, 0};
  semop(semid, &up, 1);
}

void down(int i, int semid) {
  struct sembuf down = {i, -1, 0};
  semop(semid, &down, 1);
}

int main() {
  union semun arg;
  key_t key = ftok("program1.c", 'J');
  int semid = semget(key, 1, 0);

  pid_t pid = fork();

  if(pid == 0) { // Child process
    while(1){
      down(empty, semid);
      down(mutex, semid);
      printf("Child is in critical section\n");
      up(mutex, semid);
      up(full, semid);
      sleep(2);
    }
  } else {  // Parent process
    while(1) {
      down(empty, semid);
      down(mutex, semid);
      printf("Parent is in critical section\n");
      up(mutex, semid);
      up(full, semid);
      sleep(1);
    }
  } 
  return 0;
}
