#include <iostream>
#include <vector>
using namespace std;

void dfn(int& n, int m, vector<int>& v, int& l) {
  if (m == 0) {
    for (int& i : v) {
      cout << i << ' ';
    }
    cout << '\n';
    return;
  }
  for (int i = 0; i < n; i++) {
    v[l - m] = i + 1;
    dfn(n, m - 1, v, l);
  }
}

int main() {
  int n, m;  // 4 2
  cin >> n >> m;
  vector<int> v(m);
  dfn(n, m, v, m);
  return 0;
}
