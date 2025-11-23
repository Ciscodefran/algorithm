#include <functional>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;
int INF = 1e9;
int get_dist(vector<vector<pair<int, int>>>& e, int n, int k, int r) {
  vector<int> dist(n + 1, INF);
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq;
  pq.push({0, k});
  dist[k] = 0;
  while (!pq.empty()) {
    auto [d, i] = pq.top();
    pq.pop();
    if (dist[i] < d) continue;
    for (auto [node, weight] : e[i]) {
      if (dist[node] > d + weight) {
        dist[node] = d + weight;
        pq.push({d + weight, node});
      }
    }
  }
  if (dist[r] == INF) return 0;
  return dist[r];
};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m, a, b, c;
  cin >> n >> m;
  vector<vector<pair<int, int>>> e(n + 1);
  for (int i = 0; i < m; ++i) {
    cin >> a >> b >> c;
    e[a].push_back({b, c});
  }
  string buf;
  for (int i = 1; i < n + 1; ++i) {
    for (int j = 1; j < n + 1; ++j) {
      buf.append(to_string(get_dist(e, n, i, j)));
      buf.append(" ");
    }
    buf.append("\n");
  }
  cout << buf << endl;
  return 0;
}
