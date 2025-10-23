#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> m(n, 0);
  vector<int> a(n), b(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i] >> b[i];
    for (int j = 0; j < i; ++j) {
      if (a[i] > a[j] && b[i] < b[j]) {
        m[j]++;
      }
      if (a[i] < a[j] && b[i] > b[j]) {
        m[j]++;
      }
    }
  }
  auto max_it = max_element(m.begin(), m.end());
  int cnt = 0;
  while (*max_it != 0) {
    cnt++;
    int idx = distance(m.begin(), max_it);
    for (int i = 0; i < n; ++i) {
      if (a[idx] > a[i] && b[idx] < b[i]) {
        m[i]--;
      }
      if (a[idx] < a[i] && b[idx] > b[i]) {
        m[i]--;
      }
    }

    max_it = max_element(m.begin(), m.end());
  }
  cout << cnt << endl;
  return 0;
}
