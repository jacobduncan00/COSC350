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

 umask(0);
 int fd1 = open("foo", O_CREAT | O_RDWR, 0666);
 int fd2 = dup(fd1);
 pid_t pid = fork();

 if(pid == 0){
   write(fd2, "Hi, Mom", 7);
   close(fd2);
	 return 0;
 }

 wait(NULL);
 lseek(fd1, SEEK_SET,0);
 // We know that "Hi, Mom" is only 7 so we only need a 7 char buffer
 char rbuf[7]; 
 // Read in our 7 characters
 read(fd1, rbuf, 7);
 // Print the buffer appended to the string
 printf("My son said %s\n", rbuf);
 close(fd1);
 return 0;
}
