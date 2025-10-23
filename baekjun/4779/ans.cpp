#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

void conv(vector<int>& v, int lo, int hi) {
  int l = (hi - lo + 1) / 3;
  if (l < 1) return;
  conv(v, lo, lo + l - 1);
  conv(v, lo + (l * 2), hi);
  for (int i = lo + l; i < lo + (l * 2); i++) {
    v[i] = 1;
  }
}

int main() {
  int n;
  while (cin >> n) {
    int l = static_cast<int>(pow(3, n));
    vector<int> v(l, 0);
    conv(v, 0, l - 1);
    for (int i : v) {
      cout << (i ? ' ' : '-');
    }
    cout << '\n';
  }
  return 0;
}
