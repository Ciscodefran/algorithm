#include <iostream>
using namespace std;

bool col[15]{}, d1[30]{}, d2[30]{};
void dfs(int n, int row, long long& cnt) {
  if (row == n) {
    ++cnt;
    return;
  }
  for (int c = 0; c < n; ++c) {
    if (col[c] || d1[row + c] || d2[row - c + n]) continue;
    col[c] = d1[row + c] = d2[row - c + n] = true;
    dfs(n, row + 1, cnt);
    col[c] = d1[row + c] = d2[row - c + n] = false;
  }
}
int main() {
  int n;
  cin >> n;
  long long cnt = 0;
  dfs(n, 0, cnt);
  cout << cnt;
}
