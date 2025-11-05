#include <iostream>
#include <vector>
using namespace std;

int x = 0, y = 0, z = 0;

void div(vector<vector<int>>& v, int x1, int x2, int y1, int y2) {
  if (x2 - x1 <= 0 || y2 - y1 <= 0) return;
  int _x = 0, _y = 0, _z = 0;
  for (int i = x1; i < x2; ++i) {
    for (int j = y1; j < y2; ++j) {
      if (v[i][j] == -1)
        ++_x;
      else if (v[i][j] == 0)
        ++_y;
      else
        ++_z;
    }
  }
  if (_y == 0 && _z == 0) {
    ++x;
  } else if (_x == 0 && _z == 0) {
    ++y;
  } else if (_y == 0 && _x == 0) {
    ++z;
  } else {
    int mid_x1 = x1 + (x2 - x1) / 3;
    int mid_x2 = mid_x1 + (x2 - x1) / 3;
    int mid_y1 = y1 + (y2 - y1) / 3;
    int mid_y2 = mid_y1 + (y2 - y1) / 3;
    div(v, x1, mid_x1, y1, mid_y1);
    div(v, x1, mid_x1, mid_y1, mid_y2);
    div(v, x1, mid_x1, mid_y2, y2);
    div(v, mid_x1, mid_x2, y1, mid_y1);
    div(v, mid_x1, mid_x2, mid_y1, mid_y2);
    div(v, mid_x1, mid_x2, mid_y2, y2);
    div(v, mid_x2, x2, y1, mid_y1);
    div(v, mid_x2, x2, mid_y1, mid_y2);
    div(v, mid_x2, x2, mid_y2, y2);
  }
  return;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<vector<int>> v(n, vector<int>(n, 0));
  for (vector<int>& i : v) {
    for (int& j : i) {
      cin >> j;
    }
  }
  div(v, 0, n, 0, n);
  cout << x << '\n';
  cout << y << '\n';
  cout << z << endl;
  return 0;
}
