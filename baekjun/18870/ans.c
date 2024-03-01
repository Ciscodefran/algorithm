#include <stdio.h>
#include <stdlib.h>

int compare(int *a, int *b) {
  return *a - *b;
}

int unique(int *arr, int n) {
  int j = 0;
  for (int i = 1; i < n; i++) {
    if (arr[j] != arr[i]) {
      arr[++j] = arr[i];
    }
  }
  return j + 1;
}

int b_search(int *arr, int n, int target) {
  int left = 0, right = n - 1;
  while (left <= right) {
    int mid = (left + right) / 2;
    if (arr[mid] == target) {
      return mid;
    } else if (arr[mid] < target) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  return -1;
}

int main(void) {
  int n;
  scanf("%d", &n);

  int arr[n];
  int sort[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
    sort[i] = arr[i];
  }

  qsort(sort, n, sizeof(int), (int (*)(const void *, const void *))&compare);
  int cnt = unique(sort, n);
  for (int i = 0; i < n; i++) {
    printf("%d ", b_search(sort, cnt, arr[i]));
  }
}
