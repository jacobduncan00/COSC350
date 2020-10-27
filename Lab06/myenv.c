/*
Jacob Duncan
Lab06
Task 1
myenv.c
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

extern char **environ;

char *mygetenv(char *envname)
{
	int size = strlen(envname);
	for (int i = 0; environ[i] != NULL; i++)
	{
		int j = 0;
		// Iterate over all the environment variables on system
		while (environ[i][j] != '\0')
		{
			if (j > size)
			{
				break;
			}
			else if (size == j)
			{
				if (environ[i][j] == '=')
				{
					return environ[i] + size + 1;
				}
				break;
			}
			else if (envname[j] != environ[i][j])
			{
				break;
			}
			else
			{
				// move to the next env variable
				j++;
			}
		}
	}
	// Return NULL if environment variable does not match any on system
	return NULL;
}

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("Expected 2 arguments. Ex: ./myenv [environment variable name]\n");
		return -1;
	}
	printf("EXEC: getenv(%s)\n", argv[1]);
	char *env = mygetenv(argv[1]);
	if (env != NULL)
	{
		printf("RETURN: mygetenv(%s) returned: %s\n", argv[1], env);
	}
	else
	{
		printf("RETURN: mygetenv(%s) returned: NULL\n", argv[1]);
	}
	env = getenv(argv[1]);
	if (env != NULL)
	{
		printf("RETURN: getenv(%s) returned: %s\n", argv[1], env);
	}
	else
	{
		printf("RETURN: getenv(%s) returned: NULL\n", argv[1]);
	}

	return 0;
}
