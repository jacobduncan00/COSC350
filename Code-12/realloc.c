/* realloc.c */
#include <stdio.h>
#include <stdlib.h>

int main()
{
  int *buffer;
  int i;
  /* get a initial memory block */
  buffer = (int *)malloc(10 * sizeof(int));
  if (buffer == NULL)
  {
    printf("Error allocating memory!");
    exit(1);
  }

  for (i = 0; i < 10; i++)
    buffer[i] = i;
  /* get more memory block with realloc */
  buffer = (int *)realloc(buffer, 20 * sizeof(int));

  if (buffer == NULL)
  {
    printf("Error reallocating memory!");
    //Free the initial memory block.
    free(buffer);
    exit(1);
  }

  for (i = 10; i < 20; i++)
    buffer[i] = i;
  for (i = 0; i < 20; i++)
    printf("%d, ", buffer[i]);

  printf("\n");
  free(buffer);
  return 0;
}
