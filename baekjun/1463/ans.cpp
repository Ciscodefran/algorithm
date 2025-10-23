#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int dp(int n, vector<int>& m) {
  if (n < 4) {
    return m[n];
  }
  for (int i = 4; i <= n; i++) {
    if (m[i] != 0) {
      continue;
    }
    m[i] = m[i - 1] + 1;
    if (i % 2 == 0) m[i] = min(m[i], m[i / 2] + 1);
    if (i % 3 == 0) m[i] = min(m[i], m[i / 3] + 1);
  }
  return m[n];
}

int main() {
  int n;
  cin >> n;
  vector<int> m(n + 1);
  m[1] = 0;
  m[2] = 1;
  m[3] = 1;
  cout << dp(n, m) << endl;
  return 0;
}
