#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int stringtoint(char *c)
{
  int i = 0;
  long int num = 0;
  while (c[i] != '\0')
  {
    num = 10 * num + (c[i] - '0');
    i++;
  }
  return num;
}

int main(int argc, char *argv[])
{
  int n = stringtoint(argv[1]);
  int i = 0;
  typedef struct data_type
  {
    char lname[20];
    char fname[20];
    int id;
  } data;
  char fname2[20];
  char lname2[20];
  int id2;
  data *list;
  list = (data *)calloc(n, sizeof(data));
  for (i = 0; i < n; i++)
  {
    printf("Enter first name: \n");
    scanf("%s", fname2);
    strcpy(list[i].fname, fname2);
    printf("Enter last name: \n");
    scanf("%s", lname2);
    strcpy(list[i].lname, lname2);
    printf("Enter id #: \n");
    scanf("%d", &id2);
    list[i].id = id2;
  }
  printf("\nYOUR LIST OF USERS ENTERED\n");
  int j = 0;
  for (j = 0; j < n; j++)
  {
    printf("%s %s %d\n", list[j].fname, list[j].lname, list[j].id);
  }
  free(list);
  return 0;
}
