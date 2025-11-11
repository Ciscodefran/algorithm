#include <iostream>
#include <vector>
using namespace std;
int cnt = 0;
void dfs(vector<bool>& v, vector<vector<int>>& e, int r) {
  if (v[r]) return;
  v[r] = true;
  ++cnt;
  while (!e[r].empty()) {
    int i = e[r].back();
    e[r].pop_back();
    if (!v[i]) {
      dfs(v, e, i);
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m, x, y;
  cin >> n >> m;
  vector<vector<int>> e(n + 1, vector<int>());
  vector<bool> v(n + 1, false);
  v[0] = true;
  for (int i = 0; i < m; ++i) {
    cin >> x >> y;
    e[x].push_back(y);
    e[y].push_back(x);
  }
  dfs(v, e, 1);
  cout << cnt - 1 << endl;
  return 0;
}
