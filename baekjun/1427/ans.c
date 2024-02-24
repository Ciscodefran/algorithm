#include <stdio.h>

int arr[10] = {0,};

int main() {
  int n;
  scanf("%d", &n);
  while (n > 0) {
    arr[n%10]++;
    n /= 10;
  }
  for (int i = 9; i >= 0; i--) {
    for (int j = 0; j < arr[i]; j++) {
      printf("%d", i);
    }
  }
  return 0;
}
