#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void* a, const void* b) {
  return strcmp(*(char**)a, *(char**)b);
}

int main(void) {
  int m,n;
  scanf("%d %d", &n, &m);

  char** s = (char**)malloc(sizeof(char*) * n);
  for(int i=0; i<n; i++) {
    s[i] = (char*)malloc(sizeof(char) * 501);
    scanf("%s", s[i]);
  }
  qsort(s, n, sizeof(char*), cmp);
  int cnt = 0;
  for(int i=0; i<m; i++) {
    char* t = (char*)malloc(sizeof(char) * 501);
    scanf("%s", t);
    if(bsearch(&t, s, n, sizeof(char*), cmp) != NULL) {
      cnt++;
    }
    free(t);
  }
  printf("%d\n", cnt);
  for(int i=0; i<n; i++) {
    free(s[i]);
  }

  return 0;
}
