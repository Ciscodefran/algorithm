#include <iostream>
#include <vector>

using namespace std;

void fn(vector<int>& v, int& n, int m) {
  while (v[m]) {
    fn(v, n, m - 1);
    v[m]++;
  }
}

int main() {
  int n, m;  // 4,2
  cin >> n >> m;
  vector<int> v(m, 1);  // 1로 깔고
  fn(v, n, m - 1);
  return 0;
}
