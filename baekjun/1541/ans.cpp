#include <cctype>
#include <iostream>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string str;
  // 55-50+40
  cin >> str;
  int n = 0, sum = 0;
  bool flag = true;
  for (char c : str) {
    if (!isdigit(c)) {
      if (flag) {
        sum += n;
      } else {
        sum -= n;
      }
      if (c == '-') {
        flag = false;
      }
      n = 0;
    } else {
      n *= 10;
      n += (c - '0');
    }
  }
  if (flag) {
    sum += n;
  } else {
    sum -= n;
  }
  cout << sum << endl;
  return 0;
}
