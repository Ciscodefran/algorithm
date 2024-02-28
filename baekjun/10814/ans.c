#include <stdio.h>
#include <stdlib.h>
#define MAXLEN 101

typedef struct {
  int id;
  int age;
  char name[MAXLEN];
} Person;

int cmp(const void *a, const void *b) {
  Person *p1 = (Person *)a;
  Person *p2 = (Person *)b;

  if (p1->age < p2->age) return -1;
  else if (p1->age > p2->age) return 1;
  else {
    if (p1->id < p2->id) return -1;
    else return 1;
  }
  return 0;
}

int main(void) {
  int n;
  scanf("%d", &n);
  Person people[n];
  
  for (int i = 0; i < n; i++) {
    scanf("%d %s", &people[i].age, people[i].name);
    people[i].id = i;
  }

  qsort(people, n, sizeof(Person), cmp);

  for (int i = 0; i < n; i++) {
    printf("%d %s\n", people[i].age, people[i].name);
  }
  return 0;
}
