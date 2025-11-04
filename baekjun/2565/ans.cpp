#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> x(n, 0), y(n, 0), k(n, 0);
  for (int i = 0; i < n; ++i) {
    cin >> x[i] >> y[i];
    for (int j = 0; j < i; ++j) {
      if ((x[i] > x[j] && y[i] < y[j]) || (x[i] < x[j] && y[i] > y[j])) {
        k[i]++;
        k[j]++;
      }
    }
  }
  int max = -1, idx = -1, cnt = 0;
  while (true) {
    idx = -1, max = -1;
    for (int i = 0; i < n; ++i) {
      if (k[i] > max) {
        max = k[i];
        idx = i;
      }
    }
    if (idx == -1 || max <= 0) break;
    ++cnt;
    for (int j = 0; j < n; ++j) {
      if ((x[idx] > x[j] && y[idx] < y[j]) ||
          (x[idx] < x[j] && y[idx] > y[j])) {
        k[idx]--;
        k[j]--;
      }
    }
    k[idx] = -1;
  }
  cout << cnt << endl;
  return 0;
}
