#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<int>& v, int& n, int d) {
  if (v.size() == d) {
    for (int& j : v) {
      cout << j << ' ';
    }
    cout << '\n';
    return;
  }
  for (int i = d + 1; i <= n; i++) {
    if (d > 0 && v[d - 1] >= i) {
      continue;
    }
    v[d] = i;
    dfs(v, n, d + 1);
  }
}

int main() {
  int n, m, d = 0;
  cin >> n >> m;
  vector<int> v(m, 0);
  dfs(v, n, d);
  return 0;
}
