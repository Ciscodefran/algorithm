#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

struct node {
  int index;
  int value;
  node* right;
  node* left;
};

int main() {
  int n;
  cin >> n;
  vector<node> nodes(n);
  for (int i = 0; i < n; i++) {
    nodes[i].index = i + 1;
    cin >> nodes[i].value;
    nodes[i].right = &nodes[(i + 1) % n];
    nodes[i].left = &nodes[(i - 1 + n) % n];
  }
  node* current = &nodes[0];
  for (int i = 0; i < n; i++) {
    cout << current->index << ' ';
    node* right = current->right;
    node* left = current->left;
    current->left->right = right;
    current->right->left = left;
    int step = abs(current->value);
    int jump = current->value;
    if (jump > 0) {
      for (int j = 0; j < step; j++) current = current->right;
    } else {
      for (int j = 0; j < step; j++) current = current->left;
    }
  }
  cout << '\n';
  return 0;
}
