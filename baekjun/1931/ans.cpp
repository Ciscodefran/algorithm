#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

class schedule {
  int start;
  int end;
  int len;

 public:
  void read() {
    cin >> start >> end;
    len = end - start;
  }
  int length() const { return len; }
  int end_time() const { return end; }
  int start_time() const { return start; }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, cnt = 0, last_end = INT_MIN;
  cin >> n;
  vector<schedule> v(n, schedule{});
  for (int i = 0; i < n; ++i) {
    v[i].read();
  }
  sort(v.begin(), v.end(), [](const schedule& a, const schedule& b) {
    if (a.end_time() != b.end_time()) return a.end_time() < b.end_time();
    return a.start_time() < b.start_time();
  });
  for (schedule s : v) {
    if (s.start_time() >= last_end) {
      ++cnt;
      last_end = s.end_time();
    }
  }
  cout << cnt << endl;
  return 0;
}
