#include <iostream>
#include <vector>
using namespace std;
int n, w = 0, b = 0;

void div(vector<vector<int>>& v, int x1, int x2, int y1, int y2) {
  if (x2 - x1 <= 0 || y2 - y1 <= 0) return;
  int _w = 0, _b = 0;
  for (int i = x1; i < x2; ++i) {
    for (int j = y1; j < y2; ++j) {
      if (v[i][j] == 0) {
        ++_w;
      } else {
        ++_b;
      }
    }
  }
  if (_w == 0) {
    ++b;
  } else if (_b == 0) {
    ++w;
  } else {
    int mid_x = (x1 + x2) / 2;
    int mid_y = (y1 + y2) / 2;
    div(v, x1, mid_x, y1, mid_y);
    div(v, mid_x, x2, mid_y, y2);
    div(v, x1, mid_x, mid_y, y2);
    div(v, mid_x, x2, y1, mid_y);
  }
}

int main() {
  cin >> n;
  vector<vector<int>> y(n, vector<int>(n, 0));
  for (vector<int>& x : y) {
    for (int& i : x) {
      cin >> i;
    }
  }
  div(y, 0, n, 0, n);
  cout << w << '\n' << b << endl;
  return 0;
}
