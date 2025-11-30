#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;
int mn = INT_MAX;
void bfs(vector<int>& v, int& s, int a, int b) {
  if (v[b] - v[a] >= s) {
    mn = min(mn, b - a);
    bfs(v, s, a + 1, b);
    bfs(v, s, a, b - 1);
  }
}
int main() {
  int n, s, x;
  cin >> n >> s;
  vector<int> v(n + 1);
  v[0] = 0;
  for (int i = 1; i < n + 1; ++i) {
    cin >> x;
    if (i == 1) {
      v[1] = x;
    } else {
      v[i] = v[i - 1] + x;
    }
  }
  bfs(v, s, 0, n - 1);
  cout << mn << endl;
};
