#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int cnt = 1;
void dfs(int r, vector<bool>& visited, vector<priority_queue<int>>& e,
         vector<int>& order) {
  visited[r] = true;
  order[r] = cnt++;
  auto v = e[r];
  while (!v.empty()) {
    int i = v.top();
    v.pop();
    if (!visited[i]) {
      dfs(i, visited, e, order);
    }
  }
}
int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n, m, r, u, v;
  cin >> n >> m >> r;
  vector<bool> visited(n + 1, false);
  vector<int> order(n + 1, 0);
  vector<priority_queue<int>> e(n + 1, priority_queue<int>());
  for (int i = 0; i < m; ++i) {
    cin >> u >> v;
    e[u].push(v);
    e[v].push(u);
  }
  dfs(r, visited, e, order);
  string s;
  for (int i = 1; i < n + 1; ++i) {
    s.append(to_string(order[i]));
    s.append("\n");
  }
  cout << s << endl;
  return 0;
}
