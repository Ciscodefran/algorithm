#include <stdio.h>

int main(void) {
  int n, a, b, c;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    c = 1;
    scanf("%d %d", &a, &b);
    if (a > b) {
      int tmp = a;
      a = b;
      b = tmp;
    }
    while (b*c % a != 0) {
      c++;
    }
    printf("%d\n", b*c);
  }
  return 0;
}
