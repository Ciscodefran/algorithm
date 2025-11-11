
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;
int cnt = 1;
void bfs(vector<bool>& visited, vector<priority_queue<int>>& e, int r,
         vector<int>& order) {
  visited[r] = true;
  order[r] = cnt++;
  queue<int> q;
  q.push(r);
  while (!q.empty()) {
    int i = q.front();
    q.pop();
    while (!e[i].empty()) {
      int j = e[i].top();
      e[i].pop();
      if (!visited[j]) {
        visited[j] = true;
        order[j] = cnt++;
        q.push(j);
      }
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
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
  bfs(visited, e, r, order);
  string s;
  for (int i = 1; i < n + 1; ++i) {
    s.append(to_string(order[i]));
    s.append("\n");
  }
  cout << s << endl;
  return 0;
}
