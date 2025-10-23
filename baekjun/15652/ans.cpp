#include <iostream>
#include <vector>
using namespace std;

void fn(vector<int>& v, int& n, int m, int start) {
  if (v.size() == m) {
    for (int& i : v) {
      cout << i << ' ';
    }
    cout << '\n';
    return;
  }
  for (int i = start; i < n; i++) {
    v.push_back(i + 1);
    fn(v, n, m, i);
    v.pop_back();
  }
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> v;
  fn(v, n, m, 0);
  return 0;
}
