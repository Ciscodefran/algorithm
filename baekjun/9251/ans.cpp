#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string a, b;
  cin >> a >> b;
  vector<vector<int>> v(a.length(), vector<int>(b.length(), 0));
  v[0][0] = 0;
  for (int i = 0; i < a.length(); ++i) {
    for (int j = 0; j < b.length(); ++j) {
      if (a[i] == b[j]) {
        if (i > 0 && j > 0) {
          v[i][j] = v[i - 1][j - 1] + 1;
        } else {
          v[i][j] = 1;
        }
      } else {
        if (i > 0 && j > 0) {
          v[i][j] = max(v[i - 1][j], v[i][j - 1]);
        } else if (i > 0) {
          v[i][j] = v[i - 1][j];
        } else if (j > 0) {
          v[i][j] = v[i][j - 1];
        }
      }
    }
  }
  cout << v[a.length() - 1][b.length() - 1] << endl;
  return 0;
}
