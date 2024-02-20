#include <stdio.h>

int main(n) {
  scanf("%d", &n);
  printf("%d", n-4 && n-7 ? n/5 + n%5/3 + n%5%3 : -1);
}
