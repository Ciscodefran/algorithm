#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<long long> v(n, 0), cnt(m, 0);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    if (i == 0) {
      continue;
    }
    v[i] += v[i - 1];
  }

  cnt[0] = 1;
  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    int r = v[i] % m;
    ans += cnt[r];
    cnt[r]++;
  }
  cout << ans;
  return 0;
}
