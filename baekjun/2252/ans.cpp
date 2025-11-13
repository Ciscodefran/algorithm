#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m, a, b;
  cin >> n >> m;
  vector<vector<bool>> e(n + 1, vector<bool>(n + 1, 0));
  vector<int> v(n + 1, 0);
  queue<int> q;
  for (int i = 0; i < m; ++i) {
    cin >> a >> b;
    e[a][b] = 1;
    v[b]++;
  }
  while (q.size() != n) {
    for (int i = 1; i < n + 1; ++i) {
      if (v[i] == 0) {
        v[i] = -1;
        q.push(i);
        for (int j = 1; j < n + 1; ++j) {
          if (e[i][j] != 0) {
            e[i][j] = 0;
            v[j] -= 1;
          }
        }
      }
    }
  }
  while (!q.empty()) {
    cout << q.front() << ' ';
    q.pop();
  }
  return 0;
}
