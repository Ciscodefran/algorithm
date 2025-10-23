#include <iostream>
#include <vector>
using namespace std;

constexpr int MOD = 1'000'000'000;
int main() {
  int n;
  cin >> n;
  vector<int> v(10, 1);
  v[0] = 0;
  if (n > 1) {
    for (int i = 1; i < n; ++i) {
      vector<int> m(10, 0);
      m[0] += v[1] % MOD;
      for (int d = 1; d <= 8; ++d) {
        m[d] = (v[d - 1] + v[d + 1]) % MOD;
      }
      m[9] += v[8] % MOD;
      v = m;
    }
  }
  long long sum = 0;
  for (int& i : v) {
    sum += i;
  }
  cout << sum % MOD << endl;
  return 0;
}
