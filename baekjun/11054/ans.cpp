#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, ans = 0;
  cin >> n;
  vector<int> v(n, 0), dp_asc(n, 1), dp_desc(n, 1);
  for (int& i : v) {
    cin >> i;
  }
  for (int i = 1; i < n; ++i) {
    for (int j = 0; j < i; ++j) {
      if (v[i] > v[j]) {
        dp_asc[i] = max(dp_asc[i], dp_asc[j] + 1);
      }
      if (v[n - i - 1] > v[n - j - 1]) {
        dp_desc[n - i - 1] = max(dp_desc[n - i - 1], dp_desc[n - j - 1] + 1);
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    ans = max(ans, dp_asc[i] + dp_desc[i] - 1);
  }
  cout << ans << endl;
  return 0;
}
