#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int INF = 1e9;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int v, e, x, y, z;
  cin >> v >> e;
  vector<vector<int>> m(v, vector<int>(v, INF));
  for (int i = 0; i < v; ++i) {
    m[i][i] = 0;
  }
  for (int i = 0; i < e; ++i) {
    cin >> x >> y >> z;
    m[x - 1][y - 1] = z;
  }
  for (int k = 0; k < v; ++k) {
    for (int i = 0; i < v; ++i) {
      for (int j = 0; j < v; ++j) {
        if (m[i][k] == INF || m[k][j] == INF) continue;
        m[i][j] = min(m[i][j], m[i][k] + m[k][j]);
      }
    }
  }
  int mn = INF;
  for (int i = 0; i < v; ++i) {
    for (int j = 0; j < v; ++j) {
      if (i == j) continue;
      if (m[i][j] == INF || m[j][i] == INF) continue;
      mn = min(mn, m[i][j] + m[j][i]);
    }
  }
  if (mn == INF) {
    cout << -1;
  } else {
    cout << mn;
  }
  cout << endl;
  return 0;
}
