/* calloc.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  typedef struct data_type
  {
    int age;
    char name[20];
  } data;

  data *bob;
  bob = (data *)calloc(2, sizeof(data));

  if (bob != NULL)
  {
    bob[0].age = 22;
    strcpy(bob[0].name, "Robert");
    bob[1].age = 25;
    strcpy(bob[1].name, "Christine");
    printf("%s is %d years old\n", bob[0].name, bob[0].age);
    printf("%s is %d years old\n", bob[1].name, bob[1].age);
  }

  free(bob);
  return 0;
}
