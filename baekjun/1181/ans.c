#include <stdio.h>
#include <string.h>
#define MAXLEN 50

int main(void) {
  int n;
  scanf("%d", &n);
  char words[n][MAXLEN];
  for (int i = 0; i < n; i++) {
    scanf("%s", words[i]);
  }
  for (int i = 0; i < n; i++) {
    for (int j = i+1; j < n; j++) {
      if (strlen(words[i]) > strlen(words[j])) {
        char temp[MAXLEN];
        strcpy(temp, words[i]);
        strcpy(words[i], words[j]);
        strcpy(words[j], temp);
      } else if (strlen(words[i]) == strlen(words[j])) {
        if (strcmp(words[i], words[j]) > 0) {
          char temp[MAXLEN];
          strcpy(temp, words[i]);
          strcpy(words[i], words[j]);
          strcpy(words[j], temp);
        }
      }
    }
  }
  for (int i = 0; i < n; i++) {
    printf("%s\n", words[i]);
  }
  return 0;
}
