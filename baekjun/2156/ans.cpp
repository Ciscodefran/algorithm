#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> v(n, 0), m(n, 0);
  for (int& i : v) {
    cin >> i;
  }
  m[0] = v[0];
  m[1] = v[0] + v[1];
  m[2] = max(max(v[0] + v[1], v[0] + v[2]), v[1] + v[2]);
  if (n < 3) {
    cout << m[n - 1];
    return 0;
  }
  for (int i = 3; i < n; ++i) {
    m[i] = max(m[i - 1], max(m[i - 2] + v[i], m[i - 3] + v[i - 1] + v[i]));
  }
  cout << m[n - 1];
  return 0;
}
