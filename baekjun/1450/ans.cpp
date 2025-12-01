#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, c;
  cin >> n >> c;
  vector<int> v(n);
  for (int& i : v) {
    cin >> i;
  }
  sort(v.begin(), v.end());
  int hi = 0, lo = 0;
  long long sum, cnt = 1;
  while (lo <= hi && hi < n) {
    sum = 0;
    for (int i = lo; i <= hi; ++i) {
      sum += v[i];
    }
    if (sum > c) {
      cout << pow(2, hi - lo - 1) + 1 << '\n';
      ++lo;
    } else if (sum <= c) {
      ++hi;
    }
  }
  return 0;
}
