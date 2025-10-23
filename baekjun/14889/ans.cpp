#include <climits>
#include <iostream>
#include <vector>
using namespace std;
int ans = INT_MAX;
void dfs(vector<vector<int>>& m, int& n, int b, int cnt,
         vector<int>& container) {
  if (n / 2 == cnt) {
    int a = 0, b = 0;
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        bool flag_i = false, flag_j = false;
        for (int& k : container) {
          if (k == i) flag_i = true;
          if (k == j) flag_j = true;
        }
        if (flag_i && flag_j) {
          a += m[i][j] + m[j][i];
        } else if (!flag_i && !flag_j) {
          b += m[i][j] + m[j][i];
        }
      }
    }
    ans = min(ans, abs(a - b));
    return;
  }
  for (int i = b; i < n; i++) {
    container.push_back(i);
    dfs(m, n, i + 1, cnt + 1, container);
    container.pop_back();
  }
}
int main() {
  int n;
  vector<int> container;
  cin >> n;
  vector<vector<int>> m(n, vector<int>(n));
  for (vector<int>& v : m) {
    for (int& i : v) {
      cin >> i;
    }
  }
  dfs(m, n, 0, 0, container);
  cout << ans;
  return 0;
}
