#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int x, y, tmp;
  cin >> x >> y;
  vector<vector<int>> v(y, vector<int>(x, 0));
  vector<vector<int>> step(y, vector<int>(x, 1));
  vector<pair<int, int>> chs{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
  queue<pair<int, int>> q;
  for (int i = 0; i < y; ++i) {
    for (int j = 0; j < x; ++j) {
      cin >> tmp;
      v[i][j] = tmp;
      if (tmp == 1) {
        q.push({i, j});  // y, x
      }
    }
  }
  while (!q.empty()) {
    auto [f, s] = q.front();
    q.pop();
    for (auto [a_y, a_x] : chs) {
      if (f + a_y >= 0 && f + a_y < y && s + a_x >= 0 && s + a_x < x) {
        if (v[f + a_y][s + a_x] == 0) {
          v[f + a_y][s + a_x] = 1;
          step[f + a_y][s + a_x] = step[f][s] + 1;
          q.push({f + a_y, s + a_x});
        }
      }
    }
  }
  int mx = 0;
  bool flag = false;
  for (int i = 0; i < y; ++i) {
    for (int j = 0; j < x; ++j) {
      if (v[i][j] == 0) {
        flag = true;
        break;
      }
      mx = max(step[i][j], mx);
    }
  }
  if (flag) {
    cout << -1 << endl;
  } else {
    cout << mx - 1 << endl;
  }
  return 0;
}
