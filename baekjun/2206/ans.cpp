#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m, next_x, next_y;
  cin >> n >> m;
  vector<vector<int>> v(n, vector<int>(m, 0));
  vector<vector<vector<int>>> step(2,
                                   vector<vector<int>>(n, vector<int>(m, -1)));
  vector<pair<int, int>> caret{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
  string buf;
  for (int i = 0; i < n; ++i) {
    cin >> buf;
    for (int j = 0; j < m; ++j) {
      v[i][j] = buf[j] - '0';
    }
  }
  queue<pair<int, int>> q;
  q.push({0, 0});
  step[0][0][0] = 1;
  while (!q.empty()) {
    auto [x, y] = q.front();
    q.pop();
    for (auto [a_x, a_y] : caret) {
      next_x = x + a_x;
      next_y = y + a_y;
      if (next_x >= m || next_x < 0 || next_y >= n || next_y < 0) {
        continue;
      }
      if (step[1][y][x] == -1) {
        // I didn't use the drill
        if (!v[next_y][next_x] && step[0][next_y][next_x] == -1) {
          q.push({next_x, next_y});
          step[0][next_y][next_x] = step[0][y][x] + 1;
        }
        if (v[next_y][next_x]) {
          q.push({next_x, next_y});
          step[1][next_y][next_x] = step[0][y][x] + 1;
        }
      } else {
        // I used the drill
        if (!v[next_y][next_x] && step[1][next_y][next_x] == -1 &&
            step[0][next_y][next_x] == -1) {
          q.push({next_x, next_y});
          step[1][next_y][next_x] = step[1][y][x] + 1;
        }
      }
    }
  }
  cout << max(step[0][n - 1][m - 1], step[1][n - 1][m - 1]) << endl;
  return 0;
}
