#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main()
{
	int inputFile, outputFile;
	char buf;

	// Open file foo
	inputFile = open("foo", O_RDONLY);
	if (inputFile < 0)
	{
		puts("FOO ERROR: Input file error.");
		exit(1);
	}

	umask(0);																											// Have to do this in order for the -rw-rw-rw to work on the next line, not sure why
	outputFile = open("clone1", O_RDWR | O_CREAT | O_EXCL, 0666); // 0666 stands for read, write permissions on user, group, and others
	if (outputFile < 0)
	{
		puts("CLONE1 ERROR: Output file error.");
		exit(1);
	}

	// Read byte by byte
	while (read(inputFile, &buf, 1) == 1)
	{
		write(outputFile, &buf, 1);
	}

	close(inputFile);
	close(outputFile);
	exit(0);
}
