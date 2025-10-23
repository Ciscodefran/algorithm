#include <algorithm>
#include <deque>
#include <iostream>

using namespace std;

struct Node {
  int idx;
  int v;
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, b;
  cin >> n;
  deque<Node> q;
  for (int i = 0; i < n; i++) {
    cin >> b;
    q.push_back({i + 1, b});
  }
  while (!q.empty()) {
    Node cur = q.front();
    q.pop_front();
    cout << cur.idx << ' ';
    if (q.empty()) break;
    int k = cur.v % q.size();
    if (k < 0) k += q.size();
    rotate(q.begin(), q.begin() + k, q.end());
  }
  return 0;
}
