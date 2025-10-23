#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;
int main() {
  int n, a, b, c;
  cin >> n;
  vector<int> m(3, 0);
  vector<int> tmp(3, 0);
  for (int i = 0; i < n; i++) {
    for (int& j : tmp) {
      j = INT_MAX;
    }
    cin >> a >> b >> c;
    tmp[1] = (m[0] + b) < tmp[1] ? (m[0] + b) : tmp[1];
    tmp[2] = (m[0] + c) < tmp[2] ? (m[0] + c) : tmp[2];
    tmp[0] = (m[1] + a) < tmp[0] ? (m[1] + a) : tmp[0];
    tmp[2] = (m[1] + c) < tmp[2] ? (m[1] + c) : tmp[2];
    tmp[0] = (m[2] + a) < tmp[0] ? (m[2] + a) : tmp[0];
    tmp[1] = (m[2] + b) < tmp[1] ? (m[2] + b) : tmp[1];
    m[0] = tmp[0];
    m[1] = tmp[1];
    m[2] = tmp[2];
  }
  cout << min(min(m[0], m[1]), m[2]);
  return 0;
}
