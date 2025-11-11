#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;
void dfs(vector<vector<int>>& v, int x, int y, int& o) {
  v[x][y] = false;
  ++o;
  if (v[x - 1][y]) {
    dfs(v, x - 1, y, o);
  }
  if (v[x][y - 1]) {
    dfs(v, x, y - 1, o);
  }
  if (v[x][y + 1]) {
    dfs(v, x, y + 1, o);
  }
  if (v[x + 1][y]) {
    dfs(v, x + 1, y, o);
  }
};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<vector<int>> v(n + 2, vector<int>(n + 2, 0));
  string buf;
  for (int x = 1; x < n + 1; ++x) {
    cin >> buf;
    for (int y = 1; y < n + 1; ++y) {
      v[x][y] = buf[y - 1] - '0';
    }
  }
  int cnt = 0, o = 0;
  priority_queue<int> q;
  for (int x = 1; x < n + 1; ++x) {
    for (int y = 1; y < n + 1; ++y) {
      if (v[x][y]) {
        o = 0;
        ++cnt;
        dfs(v, x, y, o);
        q.push(-o);
      }
    }
  }
  cout << cnt << '\n';
  while (!q.empty()) {
    cout << -q.top() << '\n';
    q.pop();
  }
  return 0;
};
