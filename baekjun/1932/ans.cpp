#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> input(n, 0);
  vector<int> m(n, 0);
  for (int i = 0; i < n; ++i) {
    vector<int> tmp(i + 1, 0);
    for (int j = 0; j < i + 1; ++j) {
      cin >> input[j];
      if (j == 0) {
        tmp[0] = m[0] + input[0];
      } else if (j == i) {
        tmp[j] = m[j - 1] + input[j];
      } else {
        tmp[j] = max(m[j - 1] + input[j], m[j] + input[j]);
      }
    }
    m = tmp;
  }
  int mx = 0;
  for (int& i : m) {
    mx = max(mx, i);
  }
  cout << mx << endl;
  return 0;
}
