#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> v(n, vector<int>(m, 0));
  vector<vector<int>> dp(n, vector<int>(m, 0));
  for (vector<int>& i : v) {
    for (int& j : i) {
      cin >> j;
    }
  }
  dp[n - 1][m - 1] = 1;
  return 0;
}
