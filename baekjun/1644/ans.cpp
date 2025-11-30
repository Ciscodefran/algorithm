#include <iostream>
#include <vector>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> v(n + 1, true);
  v[0] = false;
  v[1] = false;
  for (int i = 2; i < n + 1; ++i) {
    if (v[i]) {
      for (int j = 2; i * j < n + 1; ++j) {
        v[i * j] = false;
      }
    }
  }
  int lo = 2, hi = 2, cnt = 0, sum = 0;
  while (lo <= hi && hi < n + 1) {
    if (!v[hi]) {
      hi++;
      continue;
    }
    if (!v[lo]) {
      lo++;
      continue;
    }
    sum = 0;
    for (int i = lo; i <= hi; ++i) {
      if (v[i]) {
        sum += i;
      }
    }
    if (sum < n) {
      hi++;
    } else if (sum > n) {
      lo++;
    } else {
      cnt++;
      hi++;
    }
  }
  cout << cnt << endl;
  return 0;
}
