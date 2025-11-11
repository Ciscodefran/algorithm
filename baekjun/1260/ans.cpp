#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;
void dfs(vector<bool>& visited, vector<priority_queue<int>>& e, int v,
         string& buf) {
  visited[v] = true;
  buf.append(to_string(v));
  buf.append(" ");
  while (!e[v].empty()) {
    int i = -e[v].top();
    e[v].pop();
    if (!visited[i]) {
      dfs(visited, e, i, buf);
    }
  }
};
void bfs(vector<bool>& visited, vector<priority_queue<int>>& e, int v,
         string& buf) {
  visited[v] = true;
  buf.append(to_string(v));
  buf.append(" ");
  queue<int> q;
  q.push(v);
  while (!q.empty()) {
    int i = q.front();
    q.pop();
    while (!e[i].empty()) {
      int j = -e[i].top();
      e[i].pop();
      if (!visited[j]) {
        visited[j] = true;
        buf.append(to_string(j));
        buf.append(" ");
        q.push(j);
      }
    }
  }
};

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n, m, v, x, y;
  cin >> n >> m >> v;
  vector<bool> visited(n + 1, false);
  vector<bool> visited2(n + 1, false);
  vector<priority_queue<int>> e(n + 1, priority_queue<int>());
  vector<priority_queue<int>> e2(n + 1, priority_queue<int>());
  visited[0] = true;
  visited2[0] = true;
  for (int i = 0; i < m; ++i) {
    cin >> x >> y;
    e[x].push(-y);
    e[y].push(-x);
    e2[x].push(-y);
    e2[y].push(-x);
  }
  string buf;
  dfs(visited, e, v, buf);
  buf.append("\n");
  bfs(visited2, e2, v, buf);
  cout << buf << endl;
};
