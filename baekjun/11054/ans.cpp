#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n), dp_asc(n, 1), dp_desc(n, 1);
  for (int& i : a) {
    cin >> i;
  }
  for (int i = 1; i < n; ++i) {
    for (int j = 0; j < i; ++j) {
      if (a[i] > a[j]) {
        dp_asc[i] = max(dp_asc[i], dp_asc[j] + 1);
      }
    }
  }
  for (int i = n - 2; i >= 0; --i) {
    for (int j = n - 1; j > i; --j) {
      if (a[i] > a[j]) {
        dp_desc[i] = max(dp_desc[i], dp_desc[j] + 1);
      }
    }
  }
  int mx = 0;
  for (int i = 0; i < n; ++i) {
    mx = max(mx, dp_asc[i] + dp_desc[i]);
  }
  cout << mx - 1 << endl;
  return 0;
}
