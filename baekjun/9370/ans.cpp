#include <functional>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int INF = 1e9;
vector<int> get_dist(vector<vector<pair<int, int>>>& adj, int n, int s) {
  vector<int> dist(n + 1, INF);
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq;
  pq.push({0, s});
  dist[s] = 0;
  while (!pq.empty()) {
    auto [d, i] = pq.top();
    pq.pop();
    if (dist[i] < d) continue;
    for (auto [node, weight] : adj[i]) {
      if (dist[node] > d + weight) {
        dist[node] = d + weight;
        pq.push({d + weight, node});
      }
    }
  }
  return dist;
};
void test() {
  int n, m, t, s, g, h, a, b, d, e, gh_weight;
  cin >> n >> m >> t;
  cin >> s >> g >> h;
  vector<vector<pair<int, int>>> adj(n + 1);
  priority_queue<int, vector<int>, greater<int>> x;
  for (int i = 0; i < m; ++i) {
    cin >> a >> b >> d;
    adj[a].push_back({b, d});
    adj[b].push_back({a, d});
    if ((a == g && b == h) || (a == h && b == g)) {
      gh_weight = d;
    }
  }
  for (int i = 0; i < t; ++i) {
    cin >> e;
    x.push(e);
  }
  vector<int> distS, distG, distH;
  distS = get_dist(adj, n, s);
  distG = get_dist(adj, n, g);
  distH = get_dist(adj, n, h);
  int shortest, via_gh_1, via_gh_2, path_via_gh;
  while (!x.empty()) {
    auto i = x.top();
    x.pop();
    shortest = distS[i];
    via_gh_1 = distS[g] + gh_weight + distH[i];
    via_gh_2 = distS[h] + gh_weight + distG[i];
    path_via_gh = min(via_gh_1, via_gh_2);
    if (shortest != INF && shortest == path_via_gh) {
      cout << i << ' ';
    }
  }
  cout << '\n';
}
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    test();
  }
  return 0;
}
