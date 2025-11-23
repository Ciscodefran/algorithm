#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int INF = 1e9;
int main() {
  int n, m, a, b, c;
  cin >> n >> m;
  vector<int> dist(n + 1, INF);
  vector<vector<pair<int, int>>> e(n + 1);
  for (int i = 0; i < m; ++i) {
    cin >> a >> b >> c;
    e[a].push_back({c, b});
  }
  dist[1] = 0;
  for (int i = 1; i < n; ++i) {
    for (auto [d, node] : e[i]) {
      if (dist[node] > d + dist[i]) {
        dist[node] = dist[i] + d;
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
