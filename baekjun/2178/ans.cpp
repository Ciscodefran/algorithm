#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  string buf;
  vector<vector<int>> v(n + 2, vector<int>(m + 2, 0));
  vector<vector<int>> dist(n + 2, vector<int>(m + 2, 0));
  for (int i = 1; i < n + 1; ++i) {
    cin >> buf;
    for (int j = 1; j < m + 1; ++j) {
      v[i][j] = buf[j - 1] - '0';
    }
  }
  queue<pair<int, int>> q;
  q.push({1, 1});
  dist[1][1] = 1;
  v[1][1] = 0;
  while (!q.empty()) {
    auto [x, y] = q.front();
    q.pop();
    if (x == n && y == m) {
      break;
    }
    if (v[x + 1][y]) {
      v[x + 1][y] = 0;
      q.push({x + 1, y});
      dist[x + 1][y] = dist[x][y] + 1;
    }
    if (v[x - 1][y]) {
      v[x - 1][y] = 0;
      q.push({x - 1, y});
      dist[x - 1][y] = dist[x][y] + 1;
    }
    if (v[x][y + 1]) {
      v[x][y + 1] = 0;
      q.push({x, y + 1});
      dist[x][y + 1] = dist[x][y] + 1;
    }
    if (v[x][y - 1]) {
      v[x][y - 1] = 0;
      q.push({x, y - 1});
      dist[x][y - 1] = dist[x][y] + 1;
    }
  }
  cout << dist[n][m] << endl;
  return 0;
}
