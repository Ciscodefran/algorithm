#include <iostream>
#include <queue>
#include <string>
using namespace std;
struct cmp {
  bool operator()(int& a, int& b) { return abs(a) < abs(b); }
};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, k;
  cin >> n;
  priority_queue<int, vector<int>, cmp> pq;
  string s;
  for (int i = 0; i < n; ++i) {
    cin >> k;
    if (k == 0) {
      if (pq.empty()) {
        s.append("0\n");
      } else {
        s.append(to_string(-pq.top()));
        s.append("\n");
        pq.pop();
      }
    } else {
      pq.push(-k);
    }
  }
  cout << s << endl;
  return 0;
}
