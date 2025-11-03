#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, ans = 1;
  cin >> n;
  vector<int> v(n, 0), dp(n, 1);
  for (int& i : v) {
    cin >> i;
  }

  for (int i = 1; i < n; ++i) {
    for (int j = 0; j < i; ++j) {
      if (v[i] > v[j]) {
        dp[i] = max(dp[i], dp[j] + 1);
        ans = max(dp[i], ans);
      }
    }
  }
  cout << ans << endl;
  return 0;
}
