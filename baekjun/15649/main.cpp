#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<int>& v, int& n, int& m) {
  if (v.size() == m) {
    for (int& i : v) {
      cout << i << ' ';
    }
    cout << '\n';
    return;
  }
  for (int i = 1; i < n + 1; i++) {
    bool duplicated = false;
    for (int j = 0; j < v.size(); j++) {
      if (v[j] == i) {
        duplicated = true;
        break;
      }
    }
    if (duplicated) continue;
    v.push_back(i);
    dfs(v, n, m);
    v.pop_back();
  }
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> v(0);
  dfs(v, n, m);
  return 0;
}
