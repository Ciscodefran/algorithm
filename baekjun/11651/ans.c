#include <stdio.h>

void move(int a[], int b[]) {
  a[0] = b[0];
  a[1] = b[1];
}

void merge(int arr[][2], int left, int mid, int right) {
  int i, j, t;
  int temp[right+1][2];
  i = left;
  j = mid+1;
  t = left;
  while (i<=mid && j<=right) {
    if (arr[i][0] < arr[j][0]) {
      move(temp[t++], arr[i++]);
    } else if (arr[i][0] == arr[j][0]) {
      if (arr[i][1] < arr[j][1]) {
        move(temp[t++], arr[i++]);
      } else {
        move(temp[t++], arr[j++]);
      }
    } else {
      move(temp[t++], arr[j++]);
    }
  }
  if (i>mid) {
    for (int k = j; k <= right; k++) {
      move(temp[t++], arr[k]);
    }
  } else {
    for (int k = i; k <= mid; k++) {
      move(temp[t++], arr[k]);
    }
  }
  for (int k = left; k <= right; k++) {
    move(arr[k], temp[k]);
  }
}

void merge_sort(int arr[][2], int left, int right) {
  if (left < right) {
    int mid = (left + right) / 2;
    merge_sort(arr, left, mid);
    merge_sort(arr, mid+1, right);
    merge(arr, left, mid, right);
  }
}

int main(void) {
  int n;
  scanf("%d", &n);
  int arr[n][2];
  for (int i = 0; i < n; i++) {
    scanf("%d %d", &arr[i][1], &arr[i][0]);
  }
  merge_sort(arr, 0, n-1);
  for (int i = 0; i < n; i++) {
    printf("%d %d\n", arr[i][1], arr[i][0]);
  }
  
  return 0;
}
