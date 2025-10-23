#include <climits>
#include <iostream>
#include <vector>
using namespace std;
void dfs(const vector<int>& v, vector<int>& calc, vector<int>& op, int remain,
         int& min, int& max) {
  if (remain == 0) {  // op = 연산자 순열
    int result = v[0];
    for (size_t i = 0; i < op.size(); ++i) {
      switch (op[i]) {
        case 0:
          result += v[i + 1];
          break;
        case 1:
          result -= v[i + 1];
          break;
        case 2:
          result *= v[i + 1];
          break;
        default:
          result /= v[i + 1];
          break;  // C++23: 0으로 나누는 입력 없음
      }
    }
    if (result > max) {
      max = result;
    }
    if (result < min) {
      min = result;
    }
    return;
  }
  for (int i = 0; i < 4; ++i) {
    if (calc[i] == 0) continue;
    op.push_back(i);
    --calc[i];
    dfs(v, calc, op, remain - 1, min, max);
    ++calc[i];
    op.pop_back();  // 원상 복구
  }
}
int main() {
  int n, max = INT_MIN, min = INT_MAX;
  cin >> n;
  vector<int> v(n);
  vector<int> p;
  vector<int> calc(4);
  for (int& i : v) {
    cin >> i;
  }
  for (int& i : calc) {
    cin >> i;
  }
  dfs(v, calc, p, n - 1, min, max);
  cout << max << '\n';
  cout << min << '\n';
  return 0;
}
