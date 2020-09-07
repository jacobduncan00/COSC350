#include <stdio.h>
#include <string.h>

#define ARRAY_SIZE 15

int main() {

	// This is a C string, an array of characters followed by a NULL character
	char *char_ptr = "Look here";
	printf("%s\n", char_ptr);

	// More convenient way
	char char_arr[] = "Look here";
	printf("%s\n", char_arr);

	// Less convenient way
	char char_stupid[] = {'L', 'o', 'o', 'k', ' ', 'h', 'e', 'r', 'e', '\0' };
	printf("%s\n", char_stupid);

	char char_withsize[4] = "Hey";
	printf("%s\n", char_withsize);

	char char_constsize[ARRAY_SIZE] = "Hello World";
	printf("%s\n", char_constsize);

	printf("Number of characters in \'%s\' is %lu\n", char_constsize, strlen(char_constsize));

	char str1[] = "Look Here";
	char str2[] = "Look Here";

	// i will be a non-negative number because the strings are the same.
	int i = strcmp(str1, str2);
	printf("%i\n", i);

	char str3[] = "Look HerE";
	char str4[] = "Look Here";

	// j will be a negative number because the strings are not the same.
	int j = strcmp(str3, str4);
	printf("%i\n", j);

	char str5[] = "Look HerE";
	char str6[] = "Look Here";
	char str7[] = "Look Here";
	char str8[] = "Look Her";

	printf("%d\n", strcmp(str5, str6));
	printf("%d\n", strcmp(str6, str7));
	printf("%d\n", strcmp(str7, str8));

	char str9[] = "Look HerE";
	char str10[] = "Look Here";

	if (strncmp(str9, str10, 8) <= 0) {
		printf("%s\n", "Same");
	} else {
		printf("%s\n", "Not the same");
	}
	printf("%d\n", strncmp(str9, str10, 8));
	printf("%d\n", strncmp(str9, str10, 9));
	
	return 0;
}
