#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int cnt = 0;

void dfs(int r, vector<bool>& visited, vector<priority_queue<int>>& v,
         vector<int>& order) {
  if (visited[r]) return;
  visited[r] = true;
  order[r - 1] = ++cnt;
  while (!v[r].empty()) {
    auto node = v[r].top();
    v[r].pop();
    dfs(-node, visited, v, order);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m, r, u, v;
  cin >> n >> m >> r;
  vector<bool> visited(n + 1, false);
  vector<int> order(n, 0);
  vector<priority_queue<int>> nears(n + 1, priority_queue<int>());
  visited[0] = true;
  for (int i = 0; i < m; ++i) {
    cin >> u >> v;
    nears[v].push(-u);
    nears[u].push(-v);
  }
  dfs(r, visited, nears, order);
  for (auto i : order) {
    cout << i << '\n';
  }
  return 0;
}
