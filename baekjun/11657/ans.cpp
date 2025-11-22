#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int INF = 1e9;
int main() {
  int n, m, a, b, c, cnt = 0;
  cin >> n >> m;
  vector<int> dist(n + 1, INF);
  vector<vector<pair<int, int>>> e(n + 1);
  for (int i = 0; i < m; ++i) {
    cin >> a >> b >> c;
    e[a].push_back({c, b});
  }
  queue<int> q;
  q.push(1);
  dist[1] = 0;
  while (!q.empty()) {
    if (++cnt > n) {
      cout << -1 << endl;
      return 0;
    }
    int i = q.front();
    q.pop();
    for (auto [d, node] : e[i]) {
      if (dist[node] > dist[i] + d) {
        dist[node] = dist[i] + d;
        q.push(node);
      }
    }
  }
  for (int i = 2; i < n + 1; ++i) {
    if (dist[i] == INF) {
      dist[i] = -1;
    }
    cout << dist[i] << '\n';
  }
  cout << endl;
  return 0;
}
