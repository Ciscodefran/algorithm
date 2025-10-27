#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string str;
  int n, l = 0, r = 0;
  char c;
  cin >> str;
  cin >> n;
  vector<vector<int>> v(str.length(), vector<int>('z' - 'a' + 1, 0));
  for (int i = 0; i < str.length(); ++i) {
    if (i > 0) v[i] = v[i - 1];
    v[i][str[i] - 'a'] += 1;
  }
  for (int i = 0; i < n; ++i) {
    cin >> c >> l >> r;
    cout << v[r][c - 'a'] - (l > 0 ? v[l - 1][c - 'a'] : 0) << '\n';
  }
  return 0;
}
