#include <stdio.h>

int main(void) {
  int n;
  scanf("%d", &n);
  int arr[n][2];
  int *ptr[n];
  int *tmp;
  for (int i = 0; i < n; i++) {
    scanf("%d %d", &arr[i][0], &arr[i][1]);
    ptr[i] = &arr[i];
  }
  for (int i = 0; i < n; i++) {
    int x = *ptr[i];
    int y = *(ptr[i]+1);
    for (int j = 0; j < n; j++) {
      int dx = *ptr[j];
      int dy = *(ptr[j]+1);
      if (x < dx || (x == dx && y < dy)) {
        tmp = ptr[i];
        ptr[i] = ptr[j];
        ptr[j] = tmp;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    printf("%d %d\n", *ptr[i], *(ptr[i]+1));
  }
}
