#include <climits>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n, x, y, t;
  cin >> t;
  for (int k = 0; k < t; ++k) {
    cin >> n;
    vector<vector<int>> v(n, vector<int>(n, INT_MAX));
    vector<pair<int, int>> chs{{2, 1}, {-2, 1}, {2, -1}, {-2, -1},
                               {1, 2}, {-1, 2}, {1, -2}, {-1, -2}};
    cin >> x >> y;
    v[x][y] = 0;
    queue<pair<int, int>> q;
    q.push({x, y});
    cin >> x >> y;
    while (!q.empty()) {
      auto [f, s] = q.front();
      q.pop();
      int step = v[f][s] + 1;
      for (auto [a_f, a_s] : chs) {
        if (f + a_f < n && f + a_f >= 0 && s + a_s < n && s + a_s >= 0 &&
            v[f + a_f][s + a_s] > step) {
          v[f + a_f][s + a_s] = step;
          q.push({f + a_f, s + a_s});
        }
      }
    }
    cout << v[x][y] << '\n';
  }
  return 0;
}
