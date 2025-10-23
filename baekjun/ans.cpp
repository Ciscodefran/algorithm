#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> v(n, 0);
  vector<int> m(n, 0);
  vector<int> x(n, 0);
  for (int& i : v) {
    cin >> i;
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (v[i] > m[j]) {
        m[j] = v[i];
        x[j]++;
        break;
      }
    }
  }
  int mx = 0;
  for (int& i : x) {
    if (i > mx) {
      mx = i;
    }
  }
  cout << mx << endl;
  return 0;
}
