#include <iostream>
#include <vector>
using namespace std;
void dfs(vector<vector<int>>& v, int x, int y) {
  v[y][x] = 0;
  if (v[y + 1][x]) {
    dfs(v, x, y + 1);
  }
  if (v[y - 1][x]) {
    dfs(v, x, y - 1);
  }
  if (v[y][x + 1]) {
    dfs(v, x + 1, y);
  }
  if (v[y][x - 1]) {
    dfs(v, x - 1, y);
  }
}
int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int t, m, n, k, x, y;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    cin >> m >> n >> k;
    vector<vector<int>> v(n + 2, vector<int>(m + 2, 0));
    for (int j = 0; j < k; ++j) {
      cin >> x >> y;
      v[y + 1][x + 1] = 1;
    }
    int cnt = 0;
    for (int j = 1; j < n + 1; ++j) {
      for (int l = 1; l < m + 1; ++l) {
        if (v[j][l]) {
          ++cnt;
          dfs(v, l, j);
        }
      }
    }
    cout << cnt << '\n';
  }
  return 0;
}
