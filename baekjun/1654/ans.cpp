#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int n, k;

bool check(int x, vector<int>& v) {
  long long r = 0;
  for (int i = 0; i < k; ++i) {
    r += v[i] / x;
  }
  return r >= n;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> k >> n;
  vector<int> v(k, 0);
  for (int& i : v) {
    cin >> i;
  }
  long long lo = 1, hi = *max_element(v.begin(), v.end()) + 1, mid;

  if (hi == 1) {
    cout << 0;
    return 0;
  }
  while (lo + 1 < hi) {
    mid = (hi + lo) / 2;
    if (check(mid, v)) {
      lo = mid;
    } else {
      hi = mid;
    }
  }
  cout << lo << endl;
  return 0;
}
