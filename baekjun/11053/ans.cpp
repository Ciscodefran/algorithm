#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> v(n), m(n, 1);
  for (int& i : v) {
    cin >> i;
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < i; ++j) {
      if (v[j] < v[i]) {
        m[i] = max(m[i], m[j] + 1);
      }
    }
  }
  sort(m.begin(), m.end());
  cout << m[n - 1];
  return 0;
}
