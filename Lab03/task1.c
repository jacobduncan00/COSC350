//Jacob Duncan
//Sept 29, 2020
//Lab3
//task1.c

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	int fileDescriptor[2] = {0, 1}; // 0 for input, 1 for output
	int bytesFromFoo;								// Number of bytes in file Foo that can be written to file Clone
	char buf;												// Buffer which we read from foo character by character and write to clone character by character

	while ((bytesFromFoo = read(fileDescriptor[0], &buf, 1)) > 0)
	{
		write(fileDescriptor[1], &buf, bytesFromFoo);
	}

	return 0;
}
