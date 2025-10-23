#include <iostream>
using namespace std;

void move(int n, int from, int via, int to, int& k) {
  if (n == 0) return;
  move(n - 1, from, to, via, k);
  ++k;
  move(n - 1, via, from, to, k);
}

int main() {
  int n;
  cin >> n;
  int k = 0;
  move(n, 1, 2, 3, k);
  cout << k << '\n';
  return 0;
}
