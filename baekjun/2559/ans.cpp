// 첫째 줄에는 두 개의 정수 N과 K가 한 개의 공백을 사이에 두고 순서대로
// 주어진다. 첫 번째 정수 N은 온도를 측정한 전체 날짜의 수이다.
// N은 2 이상 100,000 이하이다. 두 번째 정수 K는 합을 구하기 위한
// 연속적인 날짜의 수이다. K는 1과 N 사이의 정수이다. 둘째 줄에는
// 매일 측정한 온도를 나타내는 N개의 정수가 빈칸을 사이에 두고 주어진다.
// 이 수들은 모두 -100 이상 100 이하이다.
#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, k, j, mx = INT_MIN;
  cin >> n >> k;
  vector<int> s(n);
  for (int i = 0; i < n; ++i) {
    cin >> j;
    s[i] = (i > 0) ? s[i - 1] + j : j;
    if (i > k) {
      mx = max(s[i] - s[i - k], mx);
    }
    if (i == k - 1) mx = s[i];
  }
  cout << mx << endl;
  return 0;
}
