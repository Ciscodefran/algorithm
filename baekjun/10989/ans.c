#include <stdio.h>
#define MAX 10000

int main() {
  int n;
  int v[MAX] = {0,};
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    v[x-1]++;
  }
  for (int i = 0; i < MAX; i++) {
    for (int j = 0; j < v[i]; j++) {
      printf("%d\n", i+1);
    }
  }
}
