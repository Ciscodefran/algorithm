#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<vector<bool>>& v, vector<bool>& visited, int r, int n) {
  cout << r << '\n';
  visited[r] = true;
  for (int i = 1; i <= n; ++i) {
    if (v[r][i] && !visited[i]) {
      dfs(v, visited, i, n);
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m, r;
  cin >> n >> m >> r;
  vector<vector<bool>> v(n + 1, vector<bool>(n + 1, 0));
  for (int i = 0; i < m; ++i) {
    int x, y;
    cin >> x >> y;
    v[y][x] = v[x][y] = true;
  }
  vector<bool> visited(n + 1, false);
  dfs(v, visited, r, n);
  return 0;
}
