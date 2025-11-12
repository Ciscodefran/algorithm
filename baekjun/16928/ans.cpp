#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m, x, y, next, dest;
  cin >> n >> m;
  vector<int> p(101, 0);
  vector<int> v(101, 0);
  for (int i = 0; i < n + m; ++i) {
    cin >> x >> y;
    p[x] = y;
  }
  queue<int> q;
  q.push(1);
  while (!q.empty()) {
    int i = q.front();
    q.pop();
    for (int j = 1; j < 7; j++) {
      next = i + j;
      if (next < 101 && v[next] == 0) {
        dest = p[next] ? p[next] : next;
        if (!v[dest]) {
          v[dest] = v[i] + 1;
          q.push(dest);
        }
      }
    }
  }
  cout << v[100] << endl;
  return 0;
}
