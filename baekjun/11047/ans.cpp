#include <iostream>
#include <vector>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n, k, cnt = 0;
  cin >> n >> k;
  vector<int> v(n, 0);
  for (int& i : v) {
    cin >> i;
  }
  while (k != 0) {
    if (n == 0) break;
    int x = v[n - 1];
    int r = k / x;
    if (r > 0) cnt += r;
    k = k % x;
    --n;
  }
  cout << cnt;
  return 0;
}
