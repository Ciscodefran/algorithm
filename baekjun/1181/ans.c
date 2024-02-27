#include <stdio.h>
#include <string.h>
#define MAXLEN 51

void swap(char *a, char *b) {
  char temp[MAXLEN];
  strcpy(temp, a);
  strcpy(a, b);
  strcpy(b, temp);
}

void merge(char arr[][MAXLEN], int start, int mid, int end) {
  int i = start, j = mid + 1, k = start;
  char temp[end + 1][MAXLEN];
  while (i <= mid && j <= end) {
    if (strlen(arr[i]) < strlen(arr[j])) {
      strcpy(temp[k++], arr[i++]);
    } else if (strlen(arr[i]) > strlen(arr[j])) {
      strcpy(temp[k++], arr[j++]);
    } else {
      if (strcmp(arr[i], arr[j]) < 0) {
        strcpy(temp[k++], arr[i++]);
      } else {
        strcpy(temp[k++], arr[j++]);
      }
    }
  }
  while (i <= mid) {
    strcpy(temp[k++], arr[i++]);
  }
  while (j <= end) {
    strcpy(temp[k++], arr[j++]);
  }
  for (int i = start; i <= end; i++) {
    strcpy(arr[i], temp[i]);
  }
}

void merge_sort(char arr[][MAXLEN], int start, int end) {
  if (start < end) {
    int mid = (start + end) / 2;
    merge_sort(arr, start, mid);
    merge_sort(arr, mid + 1, end);
    merge(arr, start, mid, end);
  }
}

int main(void) {
  int n;
  scanf("%d", &n);
  char words[n][MAXLEN];
  for (int i = 0; i < n; i++) {
    scanf("%s", words[i]);
  }
  merge_sort(words, 0, n - 1);
  for (int i = 0; i < n; i++) {
    if (i > 0 && strcmp(words[i], words[i - 1]) == 0) {
      continue;
    }
    printf("%s\n", words[i]);
  }
  return 0;
}
