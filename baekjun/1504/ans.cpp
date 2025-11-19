#include <algorithm>
#include <functional>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int INF = 1e9;
int get_dist(int n, vector<vector<pair<int, int>>>& adj, int start, int end) {
  vector<int> dist(n + 1, INF);
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq;
  pq.push({0, start});
  dist[start] = 0;
  while (!pq.empty()) {
    auto [d, i] = pq.top();
    pq.pop();
    if (d > dist[i]) continue;
    for (auto [node, weight] : adj[i]) {
      int x = weight + d;
      if (dist[node] > x) {
        dist[node] = x;
        pq.push({x, node});
      }
    }
  }
  return dist[end];
}
int main() {
  int n, e, a, b, c, v1, v2;
  cin >> n >> e;
  vector<vector<pair<int, int>>> adj(n + 1);
  for (int i = 0; i < e; ++i) {
    cin >> a >> b >> c;
    adj[a].push_back({b, c});
    adj[b].push_back({a, c});
  }
  cin >> v1 >> v2;
  int d1, d2, d3, d4, d5, d6, c1, c2;
  d1 = get_dist(n, adj, 1, v1);
  d2 = get_dist(n, adj, v1, v2);
  d3 = get_dist(n, adj, v2, n);
  if (d1 == INF || d2 == INF || d3 == INF) {
    c1 = INF;
  } else {
    c1 = d1 + d2 + d3;
  }
  d4 = get_dist(n, adj, 1, v2);
  d5 = get_dist(n, adj, v2, v1);
  d6 = get_dist(n, adj, v1, n);
  if (d4 == INF || d5 == INF || d6 == INF) {
    c2 = INF;
  } else {
    c2 = d4 + d5 + d6;
  }
  if (c1 == INF && c2 == INF) {
    cout << -1 << endl;
  } else {
    cout << min(c1, c2) << endl;
  }
  return 0;
}
