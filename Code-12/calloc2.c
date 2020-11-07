/* calloc2.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  int i, n;
  char name[20];
  int age;
  typedef struct
  {
    int age;
    char name[20];
  } data;

  data *list;
  printf("Number of students to be entered in the list:");
  scanf("%d", &n);
  list = (data *)calloc(n, sizeof(data));

  for (i = 0; i < n; i++)
  {
    printf("Enter name: \n");
    scanf("%s", name);
    strcpy(list[i].name, name);
    printf("Enter age: \n");
    scanf("%d", &age);
    list[i].age = age;
  }

  printf("YOUR STUDENT LIST\n");
  for (i = 0; i < n; i++)
  {
    printf("%s %d \n", list[i].name, list[i].age);
  }

  free(list);
  return 0;
}
