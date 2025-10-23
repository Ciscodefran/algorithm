#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  vector<int> v(n, 1);
  for (int i = 0; i < m; i++) {
    v[i] = 0;
  }

  do {
    for (int i = 0; i < n; i++) {
      if (v[i] == 0) {
        cout << i + 1 << ' ';
      }
    }
    cout << '\n';
  } while (next_permutation(v.begin(), v.end()));

  return 0;
}
