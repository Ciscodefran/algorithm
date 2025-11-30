#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, a, b;
  cin >> n;
  vector<long long> v(n);
  for (long long& i : v) {
    cin >> i;
  }
  long long mn = 2000000000, sm;
  for (int i = 0; i < n - 1; ++i) {
    for (int j = i + 1; j < n; ++j) {
      sm = abs(v[i] + v[j]);
      if (sm < mn) {
        mn = sm;
        a = i;
        b = j;
      }
    }
  }
  if (v[a] > v[b]) {
    cout << v[b] << ' ' << v[a] << endl;
  } else {
    cout << v[a] << ' ' << v[b] << endl;
  }
  return 0;
}
