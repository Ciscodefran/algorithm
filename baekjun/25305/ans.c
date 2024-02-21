#include <stdio.h>

int main(void) {
  int n, k;
  scanf("%d %d", &n, &k);
  int x[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &x[i]);
  }
  for (int i = 0; i < n; i++) {
    for (int j = i+1; j < n; j++) {
      if (x[j] > x[i]) {
        int temp = x[i];
        x[i] = x[j];
        x[j] = temp;
      }
    }
  }
  printf("%d\n", x[k - 1]);
  return 0;
}
