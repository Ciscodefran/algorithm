#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n, sum = 0;
  cin >> n;
  vector<int> v(n, 0);
  for (int &i : v) {
    cin >> i;
  }
  sort(v.begin(), v.end());
  for (int i = 0; i < n; ++i) {
    if (i > 0) {
      v[i] += v[i - 1];
    }
    sum += v[i];
  }
  cout << sum;
  return 0;
}
