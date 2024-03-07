#include <stdio.h>

int compare(const void *a, const void *b) {
  return *(int *)a - *(int *)b;
}

int main(void) {
  int m, n;
  scanf("%d %d", &m, &n);
  int a[m], b[n];
  for (int i = 0; i < m; i++) {
    scanf("%d", &a[i]);
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &b[i]);
  }
  qsort(a, m, sizeof(int), compare);
  qsort(b, n, sizeof(int), compare);
  int i = 0, j = 0, count = 0;
  while (i < m && j < n) {
    if (a[i] < b[j]) {
      i++;
    } else if (a[i] > b[j]) {
      j++;
    } else {
      i++;
      j++;
      count++;
    }
  }
  printf("%d\n", m + n - 2 * count);
  return 0;
}
