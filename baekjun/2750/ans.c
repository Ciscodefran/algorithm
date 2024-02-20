#include <stdio.h>

int main(void) {
  int v[1000];
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &v[i]);
  }
  for (int i = 0; i<n; i++) {
    for (int j = i; j<n; j++) {
      if (v[i] > v[j]) {
        int temp = v[i];
        v[i] = v[j];
        v[j] = temp;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    printf("%d\n", v[i]);
  }
  return 0;
}
