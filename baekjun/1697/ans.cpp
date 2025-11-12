#include <climits>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int len = 200000 + 2;
int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n, k;
  cin >> n >> k;
  vector<int> v(len, INT_MAX);
  v[n] = 0;
  queue<int> q;
  q.push(n);
  while (!q.empty()) {
    int i = q.front();
    q.pop();
    int step = v[i] + 1;
    if (i + 1 < len && v[i + 1] > step) {
      v[i + 1] = step;
      q.push(i + 1);
    }
    if (i - 1 >= 0 && v[i - 1] > step) {
      v[i - 1] = step;
      q.push(i - 1);
    }
    if (i * 2 < len && v[i * 2] > step) {
      v[i * 2] = step;
      q.push(i * 2);
    }
  }
  cout << v[k] << endl;
};
