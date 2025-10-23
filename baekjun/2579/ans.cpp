#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int dp(int n, vector<int>& v, vector<int>& m) {
  if (n < 3) {
    return m[n - 1];
  }
  for (int i = 3; i < n; ++i) {
    m[i] = max(m[i - 2], m[i - 3] + v[i - 1]) + v[i];
  }
  return m[n - 1];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> v(n, 0), m(n, 0);
  for (int& i : v) {
    cin >> i;
  }
  m[0] = v[0];
  m[1] = v[0] + v[1];
  m[2] = max(v[0], v[1]) + v[2];
  cout << dp(n, v, m) << endl;
  return 0;
}
