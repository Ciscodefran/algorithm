#include <functional>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

int INF = 1e9;
int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n, e, k, u, v, w;
  cin >> n >> e >> k;
  vector<vector<pair<int, int>>> adj(n + 1);
  vector<int> dist(n + 1, INF);
  for (int i = 0; i < e; ++i) {
    cin >> u >> v >> w;
    adj[u].push_back({v, w});
  }
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq;
  pq.push({0, k});
  dist[k] = 0;
  while (!pq.empty()) {
    auto [d, i] = pq.top();
    pq.pop();
    if (d > dist[i]) continue;  // ?
    for (auto [node, weight] : adj[i]) {
      if (dist[node] > d + weight) {
        dist[node] = d + weight;
        pq.push({d + weight, node});
      }
    }
  }
  string buf;
  for (int i = 1; i < n + 1; ++i) {
    if (dist[i] == INF) {
      buf.append("INF\n");
    } else {
      buf.append(to_string(dist[i]));
      buf.append("\n");
    }
  }
  cout << buf << endl;
  return 0;
}
