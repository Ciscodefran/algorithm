#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n + 1), nxt(n + 1), prv(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    nxt[i] = i == n ? 1 : i + 1;
    prv[i] = i == 1 ? n : i - 1;
  }
  int cur = 1;
  int step, val;
  for (int i = 0; i < n; i++) {
    cout << cur << " ";
    val = a[cur];
    step = abs(val);
    nxt[prv[cur]] = nxt[cur];
    prv[nxt[cur]] = prv[cur];
    if (val > 0) {
      for (int j = 0; j < step; j++) {
        cur = nxt[cur];
      }
    } else {
      for (int j = 0; j < step; j++) {
        cur = prv[cur];
      }
    }
  }
  cout << '\n';
  return 0;
}
