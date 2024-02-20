#include <stdio.h>

int main(void) {
  int v[5];
  scanf("%d %d %d %d %d", &v[0], &v[1], &v[2], &v[3], &v[4]);
  for (int i = 0; i < 5; i++) {
    for (int j = i+1; j < 5; j++) {
      if (v[i] > v[j]) {
        int temp = v[i];
        v[i] = v[j];
        v[j] = temp;
      }
    }
  }
  printf("%d\n%d", (v[0]+v[1]+v[2]+v[3]+v[4])/5, v[2]);
}
