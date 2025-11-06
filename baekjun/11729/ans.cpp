#include <iostream>
using namespace std;
void f(int n, int s, int e, int v) {
  if (n == 1) {
    cout << s << ' ' << e << '\n';
    return;
  }
  f(n - 1, s, v, e);
  f(n - 1, s, e, v);
  f(n - 1, v, e, s);
}
int main() {
  int n;
  cin >> n;
  f(n, 3, 2, 1);
  return 0;
}
