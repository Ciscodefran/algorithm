#include <stdio.h>

int search(int n) {
  for (int i = n; i >= 666; i/=0)
    if (i % 1000 == 666) return 1;
  return 0;
}

int main(void) {
  
}
