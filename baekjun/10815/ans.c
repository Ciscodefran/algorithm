#include <stdio.h>

int compare(const void *a, const void *b) {
  return *(int *)a - *(int *)b;
}

int binary_search(int *arr, int n, int target) {
  int start = 0, end = n - 1;
  while (start <= end) {
    int mid = (start + end) / 2;
    if (arr[mid] == target) {
      return 1;
    } else if (arr[mid] > target) {
      end = mid - 1;
    } else {
      start = mid + 1;
    }
  }
  return 0;
}

int main(void) {
  int n, m;
  scanf("%d", &n);
  int cards[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &cards[i]);
  }

  qsort(cards, n, sizeof(int), compare);

  scanf("%d", &m);
  for (int i = 0; i < m; i++) {
    int target;
    scanf("%d", &target);
    printf("%d ", binary_search(cards, n, target));
  }

  return 0;
}
