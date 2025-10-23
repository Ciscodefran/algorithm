#include <iostream>
#include <vector>
using namespace std;

int fib(int n, int& cnt) {
  if (n == 1 || n == 2) {
    cnt++;
    return 1;
  } else
    return fib(n - 1, cnt) + fib(n - 2, cnt);
}

int fibonacci(int n, vector<int>& v, int& cnt) {
  v[1] = v[2] = 1;
  for (int i = 3; i <= n; i++) {
    v[i] = v[i - 1] + v[i - 2];
    cnt++;
  }
  return v[n];
}

int main() {
  int n, a = 0, b = 0;
  cin >> n;
  vector<int> v(n + 1);
  fib(n, a);
  fibonacci(n, v, b);
  cout << a << '\n' << b << endl;
  return 0;
}
