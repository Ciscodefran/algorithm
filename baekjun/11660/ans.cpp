#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> w(n, vector<int>(n, 0));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> w[i][j];
      w[i][j] += (j > 0) ? w[i][j - 1] : 0;
      w[i][j] += (i > 0) ? w[i - 1][j] : 0;
      w[i][j] -= (i > 0 && j > 0) ? w[i - 1][j - 1] : 0;
    }
  }
  int x1, x2, y1, y2;
  for (int i = 0; i < m; ++i) {
    cin >> x1 >> y1 >> x2 >> y2;
    int x = w[x2 - 1][y2 - 1];
    x += (x1 - 2 >= 0 && y1 - 2 >= 0) ? w[x1 - 2][y1 - 2] : 0;
    x -= (x1 - 2 >= 0) ? w[x1 - 2][y2 - 1] : 0;
    x -= (y1 - 2 >= 0) ? w[x2 - 1][y1 - 2] : 0;
    cout << x << '\n';
  }
  return 0;
}
