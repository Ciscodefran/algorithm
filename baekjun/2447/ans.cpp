#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

void fn(vector<vector<int>>& vv, int x, int y, int to) {
  if (to < 3) return;
  int d = to / 3;
  for (int i = x; i < x + to; i += d) {
    for (int j = y; j < y + to; j += d) {
      if (i == x + d && j == y + d) {
        for (int k = x + d; k < x + d * 2; k++) {
          for (int l = y + d; l < y + d * 2; l++) {
            vv[k][l] = 0;
          }
        }
      } else {
        fn(vv, i, j, d);
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<vector<int>> vv(n, vector<int>(n, 1));
  fn(vv, 0, 0, n);
  for (const vector<int>& v : vv) {
    for (int i : v) {
      cout << ((i == 0) ? ' ' : '*');
    }
    cout << '\n';
  }
  cout << '\n';
  return 0;
}
