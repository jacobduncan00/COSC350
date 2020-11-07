/* malloc.c */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  typedef struct
  {
    int age;
    char name[20];
  } data;

  data *bob;
  bob = (data *)malloc(sizeof(data));

  if (bob != NULL)
  {
    bob->age = 22;
    strcpy(bob->name, "Robert");
    printf("%s is %d years old\n", bob->name, bob->age);
  }

  free(bob);
  return 0;
}
