#include <iostream>
#include <queue>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, k;
  cin >> n;
  priority_queue<int> pq;
  for (int i = 0; i < n; ++i) {
    cin >> k;
    if (k == 0) {
      if (pq.size() > 0) {
        cout << pq.top() << '\n';
        pq.pop();
      } else {
        cout << "0\n";
      }
    } else {
      pq.push(k);
    }
  }
  return 0;
}
