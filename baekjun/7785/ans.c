#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _NODE {
  char name[6];
  char status;
  struct _NODE *Left;
  struct _NODE *Right;
} NODE;
int compare(const void *a, const void *b) {
  return strcmp((char *)a, (char *)b);
}
void makeNode(NODE *p, char *name, char status) {
  printf("makeNode: %s %c\n", name, status);
  p = (NODE *)malloc(sizeof(NODE));
  strcpy(p->name, name);
  p->status = status;
  p->Left = NULL;
  p->Right = NULL;
}
// insert
void insert(NODE *root, char *name, char status) {
  if (root == NULL) {
    makeNode(root, name, status);
  } else {
    printf("insert: %s %c\n", name, status);
    NODE *cur = root;
    while (1) {
      int cmp = strcmp(cur->name, name);
      printf("name cmp: %s %d\n", cur->name, cmp);
      if (cmp > 0) {
        if (cur->Left == NULL) {
          makeNode(cur->Left, name, status);
          break;
        } else {
          cur = cur->Left;
        }
      } else if (cmp < 0) {
        if (cur->Right == NULL) {
          makeNode(cur->Right, name, status);
          break;
        } else {
          cur = cur->Right;
        }
      } else {
        cur->status = status;
      }
    }
  }
}
void recursive_traverse(NODE *ptr) {
  if (ptr != NULL) {
    recursive_traverse(ptr->Left);
    if (ptr->status == 'e') {
      printf("%s\n", ptr->name);
    }
    recursive_traverse(ptr->Right);
  }
}

int main(void) {
  NODE *root;
  int n;
  char name[6], status[6];
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%s %s", name, status);
    if (strcmp(status, "enter") == 0) {
      insert(root, name, 'e');
    } else {
      insert(root, name, 'l');
    }
  }
  recursive_traverse(root);

  return 0;
}
