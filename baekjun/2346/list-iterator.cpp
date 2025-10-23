#include <iostream>
#include <list>

using namespace std;

struct Node {
  int idx;
  int value;
};

int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;  // 5
  cin >> n;
  list<Node> l;
  int b;
  for (int i = 0; i < n; i++) {
    cin >> b;
    l.push_back({i + 1, b});  // 3 2 1 -3 -1
  }
  list<Node>::iterator it = l.begin();
  // {1, 3}, {2, 2}, {3, 1}, {4, -3}, {5, -1}
  for (int step = 0; !l.empty();) {
    step = it->value;        // 3
    cout << it->idx << ' ';  // 1
    it = l.erase(it);        // {2, 2}
    if (it == l.end()) it = l.begin();
    if (l.empty()) break;
    if (step > 0) {
      for (int i = 1; i < abs(step); i++) {
        it++;
        if (it == l.end()) it = l.begin();
      }
    } else {
      for (int i = 0; i < abs(step); i++) {
        if (it == l.begin()) it = l.end();
        it--;
      }
    }
  }
  return 0;
}
