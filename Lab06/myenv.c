#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

extern char **realenv;

char *mygetenv(char* envname) {
	int size = strlen(envname);
	for(int i = 0; realenv[i] != NULL; i++) {
		int j = 0;
		while(realenv[i][j] != '\0') {
			if (j > size) {
				break;
			} else if (size == j) {
				if (realenv[i][j] == '=') {
					return realenv[i] + size + 1;
				}
				else {
					break;
				}
			} else if (envname[j] != realenv[i][j]) {
				break;
			} else {
				j++;
			}
		}
	}
	return NULL;
}

int main(int argc, char *argv[]) {
	if (argc != 2) {
		printf("Expected 2 arguments. Ex: ./myenv [environment variable name]\n");
		return -1;
	}
	printf("EXEC: getenv(%s)\n", argv[1]);
	char *env = mygetenv(argv[1]);
	if (env != NULL) {
		printf("RETURN: mygetenv(%s) returned: %s\n", argv[1], env);
	} else {
		printf("RETURN: mygetenv(%s) returned: NULL\n", argv[1]);
	}
	env = getenv(argv[1]);
	if (env != NULL) {
		printf("RETURN: getenv(%s) returned: %s\n", argv[1], env);
	} else {
		printf("RETURN: getenv(%s) returned: NULL\n", argv[1]);
	}

	return 0;
}

