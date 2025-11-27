#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, cnt = 0, x;
  cin >> n;
  vector<int> v(n);
  for (int& i : v) {
    cin >> i;
  }
  cin >> x;
  for (int i = 0; i < n - 1; ++i) {
    for (int j = i + 1; j < n; ++j) {
      if (v[i] + v[j] == x) {
        ++cnt;
      }
    }
  }
  cout << cnt << endl;
  return 0;
}
