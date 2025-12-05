#include <iostream>
#include <vector>
using namespace std;
int main() {
  int n, c, r;
  cin >> n;
  vector<pair<int, int>> v(n);
  vector<vector<int>> dp(n, vector<int>(n, 0));
  for (int i = 0; i < n; ++i) {
    cin >> r >> c;
    v[i] = {r, c};
    if (i > 1) {
      dp[i - 1][i] = v[i - 1].first * v[i].first * v[i].second;
    }
  }
  return 0;
}
