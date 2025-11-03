#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> dp(n, 0), v(n, 0);
  for (int& i : v) {
    cin >> i;
  }
  if (n == 1) return v[0];
  dp[0] = v[0];
  if (n == 2) return v[0] + v[1];
  dp[1] = v[0] + v[1];
  dp[2] = max({v[0] + v[1], v[1] + v[2], v[0] + v[2]});
  for (int i = 3; i < n; i++) {
    dp[i] = max(
        {dp[i - 3] + v[i - 2] + v[i], dp[i - 3] + v[i - 1] + v[i], dp[i - 1]});
    // dp[i] = max({dp[i - 1], dp[i - 2] + v[i], dp[i - 3] + v[i - 1] + v[i]});
  }
  cout << dp[n - 1] << endl;
  return 0;
}
