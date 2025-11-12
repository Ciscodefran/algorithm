#include <algorithm>
#include <iostream>
#include <queue>
#include <tuple>
#include <vector>
using namespace std;
int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int m, n, h, k;
  cin >> m >> n >> h;
  queue<tuple<int, int, int>> q;
  vector<tuple<int, int, int>> caret{{1, 0, 0},  {-1, 0, 0}, {0, 1, 0},
                                     {0, -1, 0}, {0, 0, 1},  {0, 0, -1}};
  vector<vector<vector<int>>> v(h, vector<vector<int>>(n, vector<int>(m, -1)));
  vector<vector<vector<int>>> cnt(h, vector<vector<int>>(n, vector<int>(m, 0)));
  for (int z = 0; z < h; ++z) {
    for (int y = 0; y < n; ++y) {
      for (int x = 0; x < m; ++x) {
        cin >> k;
        v[z][y][x] = k;
        if (k == 1) {
          q.push({x, y, z});
        }
      }
    }
  }
  while (!q.empty()) {
    auto [x, y, z] = q.front();
    q.pop();
    for (auto [a_x, a_y, a_z] : caret) {
      if (x + a_x >= m || x + a_x < 0) {
        continue;
      }
      if (y + a_y >= n || y + a_y < 0) {
        continue;
      }
      if (z + a_z >= h || z + a_z < 0) {
        continue;
      }
      if (v[z + a_z][y + a_y][x + a_x] == 0) {
        v[z + a_z][y + a_y][x + a_x] = 1;
        cnt[z + a_z][y + a_y][x + a_x] = cnt[z][y][x] + 1;
        q.push({x + a_x, y + a_y, z + a_z});
      }
    }
  }

  int day = 0;
  bool flag = false;
  for (int z = 0; z < h; ++z) {
    for (int y = 0; y < n; ++y) {
      for (int x = 0; x < m; ++x) {
        day = max(day, cnt[z][y][x]);
        if (v[z][y][x] == 0) {
          flag = true;
          break;
        }
      }
    }
  }
  if (flag) {
    day = -1;
  }
  cout << day << endl;
};
