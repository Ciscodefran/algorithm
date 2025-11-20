#include <functional>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int MX = 200000;
int INF = 1e9;
int main() {
  int n, k;
  cin >> n >> k;
  vector<int> dist(MX, INF);
  dist[n] = 0;
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq;
  pq.push({0, n});
  while (!pq.empty()) {
    auto [d, i] = pq.top();
    pq.pop();
    if (dist[i] < d) continue;
    if (2 * i < MX && d < dist[2 * i]) {
      dist[2 * i] = d;
      pq.push({d, 2 * i});
    }
    if (i + 1 < MX && d + 1 < dist[i + 1]) {
      dist[i + 1] = d + 1;
      pq.push({d + 1, i + 1});
    }
    if (i - 1 >= 0 && d + 1 < dist[i - 1]) {
      dist[i - 1] = d + 1;
      pq.push({d + 1, i - 1});
    }
  }
  cout << dist[k] << endl;
  return 0;
}
