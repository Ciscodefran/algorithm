#include <iostream>
#include <vector>
using namespace std;

// 첫째 줄에 수의 개수 N과 합을 구해야 하는 횟수 M이 주어진다.
// 둘째 줄에는 N개의 수가 주어진다. 수는 1,000보다 작거나
// 같은 자연수이다. 셋째 줄부터 M개의 줄에는 합을 구해야 하는 구간 i와 j가
// 주어진다.

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m, l = 0, f, e;
  cin >> n >> m;
  vector<int> sum(n, 0);
  for (int i = 0; i < n; ++i) {
    cin >> sum[i];
    if (i != 0) {
      sum[i] += sum[i - 1];
    }
  }
  string out;
  for (int i = 0; i < m; ++i) {
    cin >> f >> e;
    out += to_string((sum[e - 1] - sum[f - 2]));
    out += '\n';
  }
  cout << out << endl;
  return 0;
}
