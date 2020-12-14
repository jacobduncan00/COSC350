#include <stdlib.h>
#include <stdio.h>

int main() {

  char *userInput = (char *)calloc(256, sizeof(int));

  while(1) {
      puts("Enter two integer values: ");
      fgets(userInput, 256, stdin);
      if (feof(stdin)) {
          printf("EOF");
          return 0;
      }
      int i, j;
      sscanf(userInput, "%d%d", &i, &j);
      printf("You entered: %d & %d\n", i, j);
  }
  return 0;
}
