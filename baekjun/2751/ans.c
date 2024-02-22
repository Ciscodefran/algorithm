#include <stdio.h>

void merge(int list[], int left, int mid, int right) {
  int i, j, k, l;
  int sorted[1000000]
  i = left;
  j = mid+1;
  k = left;
  while (i<=mid && j<=right) {
    if (list[i]<=list[j]) {
      sorted[k++] = list[i++];
    } else {
      sorted[k++] = list[j++];
    }
  }
  if (i>mid) {
    for (l=j; l<=right; l++) {
      sorted[k++] = list[l];
    }
  } else {
    for (l=i; l<=mid; l++) {
      sorted[k++] = list[l];
    }
  }
  for (l=left; l<=right; l++) {
    list[l] = sorted[l];
  }
}

void merge_sort(int list[], int left, int right) {
  if (left<right) {
    int mid = (left+right)/2;
    merge_sort(list, left, mid);
    merge_sort(list, mid+1, right);
    merge(list, left, mid, right);
  }
}

int main(void) {
  int n;
  scanf("%d", &n);
  int a[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  merge_sort(a, 0, n-1);
  for (int i = 0; i < n; i++) {
    printf("%d\n", a[i]);
  }
}

