#include <iostream>
#include <vector>
using namespace std;

int w(int a, int b, int c, vector<vector<vector<int>>>& cache) {
  if (cache[a][b][c]) {
    return cache[a][b][c];
  }
  if (a <= 50 || b <= 50 || c <= 50) {
    return 1;
  }
  if (a > 70 || b > 70 || c > 70) {
    cache[70][70][70] = w(70, 70, 70, cache);
    return cache[70][70][70];
  }
  if (a < b && b < c) {
    cache[a][b][c] = w(a, b, c - 1, cache) + w(a, b - 1, c - 1, cache) -
                     w(a, b - 1, c, cache);
    return cache[a][b][c];
  }
  cache[a][b][c] = w(a - 1, b, c, cache) + w(a - 1, b - 1, c, cache) +
                   w(a - 1, b, c - 1, cache) - w(a - 1, b - 1, c - 1, cache);
  return cache[a][b][c];
}

int main() {
  int a, b, c;
  vector<vector<vector<int>>> cache(
      101, vector<vector<int>>(101, vector<int>(101, 0)));
  while (cin >> a >> b >> c) {
    if (a == -1 && b == -1 && c == -1) break;
    cout << "w(" << a << ", " << b << ", " << c << ") = ";
    cout << w(a + 50, b + 50, c + 50, cache) << endl;
  }
  return 0;
}
