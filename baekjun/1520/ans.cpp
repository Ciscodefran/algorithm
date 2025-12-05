#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> v(n, vector<int>(m, 0));
  for (vector<int>& i : v) {
    for (int& j : i) {
      cin >> j;
    }
  }
  queue<pair<int, int>> q;
  q.push({0, 0});
  int cnt = 0;
  while (!q.empty()) {
    auto [x, y] = q.front();
    q.pop();
    if (x == m - 1 && y == n - 1) {
      ++cnt;
      continue;
    }
    if (0 <= x && x < m - 1 && v[y][x + 1] < v[y][x]) {
      q.push({x + 1, y});
    }
    if (0 < x && x < m && v[y][x - 1] < v[y][x]) {
      q.push({x - 1, y});
    }
    if (0 <= y && y < n - 1 && v[y + 1][x] < v[y][x]) {
      q.push({x, y + 1});
    }
    if (0 < y && y < n && v[y - 1][x] < v[y][x]) {
      q.push({x, y - 1});
    }
  }
  cout << cnt << endl;
  return 0;
}
