#include <iostream>
#include <vector>
using namespace std;

void div(vector<vector<int>>& v, int x1, int x2, int y1, int y2) {
  if (x2 - x1 <= 0 || y2 - y1 <= 0) return;
  int b = 0, w = 0;
  for (int i = x1; i < x2; ++i) {
    for (int j = y1; j < y2; ++j) {
      if (v[i][j] == 0)
        ++w;
      else
        ++b;
    }
  }
  if (b == 0) {
    cout << '0';
  } else if (w == 0) {
    cout << '1';
  } else {
    cout << '(';
    int mid_x = (x1 + x2) / 2;
    int mid_y = (y1 + y2) / 2;
    div(v, x1, mid_x, y1, mid_y);
    div(v, x1, mid_x, mid_y, y2);
    div(v, mid_x, x2, y1, mid_y);
    div(v, mid_x, x2, mid_y, y2);
    cout << ')';
  }
  return;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<vector<int>> v(n, vector<int>(n, 0));
  for (int r = 0; r < n; ++r) {
    string s;
    cin >> s;
    for (int c = 0; c < n; ++c) v[r][c] = s[c] - '0';
  }
  div(v, 0, n, 0, n);
  cout << endl;
  return 0;
}
