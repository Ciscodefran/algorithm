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
  Node tmp;
  for (int i = 0; i < n; i++) {
    Node cur = q.front();
    q.pop_front();
    cout << cur.idx << ' ';
    if (cur.v > 0) {
      for (int j = 1; j < abs(cur.v); j++) {
        tmp = q.front();
        q.pop_front();
        q.push_back(tmp);
      }
    } else {
      for (int j = 0; j < abs(cur.v); j++) {
        tmp = q.back();
        q.pop_back();
        q.push_front(tmp);
      }
    }
  }
  return 0;
}
