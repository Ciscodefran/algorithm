#include <climits>
#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<int>& v, int n, int sum, int sub, int mul, int div, int i,
         int& max, int& min) {
  if (sum < 0 || sub < 0 || mul < 0 || div < 0) {
    return;
  } else if (i == v.size()) {
    max = n > max ? n : max;
    min = n < min ? n : min;
    return;
  }
  dfs(v, n + v[i], sum - 1, sub, mul, div, i + 1, max, min);
  dfs(v, n - v[i], sum, sub - 1, mul, div, i + 1, max, min);
  dfs(v, n * v[i], sum, sub, mul - 1, div, i + 1, max, min);
  dfs(v, n / v[i], sum, sub, mul, div - 1, i + 1, max, min);
}

int main() {
  int n, sum, sub, mul, div, max = INT_MIN, min = INT_MAX;
  cin >> n;
  vector<int> v(n);
  for (int& i : v) {
    cin >> i;
  }
  cin >> sum;
  cin >> sub;
  cin >> mul;
  cin >> div;
  int calc = v[0];
  dfs(v, calc, sum, sub, mul, div, 1, max, min);
  cout << max << '\n';
  cout << min << '\n';
  return 0;
}
