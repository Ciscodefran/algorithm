#include <iostream>
#include <vector>
using namespace std;
bool dp(int x, int d, vector<int>& w) {
  if (x == 0) {
    if (d == 0) {
      return true;
    } else {
      return false;
    }
  }
  return dp(x - 1, d, w) || dp(x - 1, abs(d - w[x]), w) ||
         dp(x - 1, d + w[x], w);
}
int main() {
  int n, m, k;
  cin >> n;
  vector<int> w(n);
  for (int i = 0; i < n; ++i) {
    cin >> w[i];
  }
  cin >> m;
  for (int i = 0; i < m; ++i) {
    cin >> k;
    dp(n, k, w);
  }
  return 0;
}
