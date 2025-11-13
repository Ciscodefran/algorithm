#include <iostream>
using namespace std;
int cnt = 0;
string buf;
void hanoi(int s, int e, int v, int n) {
  if (n == 1) {
    ++cnt;
    buf.append(to_string(s));
    buf.append(" ");
    buf.append(to_string(e));
    buf.append("\n");
    return;
  }
  hanoi(s, v, e, n - 1);
  hanoi(s, e, v, 1);
  hanoi(v, e, s, n - 1);
}
int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  hanoi(1, 3, 2, n);
  cout << cnt << '\n' << buf;
  return 0;
};
