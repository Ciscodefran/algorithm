#include <cmath>
#include <iostream>
const int LEN = 4000;
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, tmp, walker = 0;
  int sum = 0, mid = 0, avg = 0, most = 0, many = -LEN - 1, min = LEN * 2 + 1,
      max = -LEN;
  cin >> n;
  int cnt[LEN * 2 + 1] = {0};
  bool second = false;
  bool found = false;

  for (int i = 0; i < n; i++) {
    cin >> tmp;
    cnt[LEN + tmp] += 1;
  }
  walker = (n - 1) / 2;
  for (int i = 0; i < LEN * 2 + 1; i++) {
    if (cnt[i] > 0) {
      sum += cnt[i] * (i - LEN);
      walker -= cnt[i];
      if (walker < 0 && !found) {
        mid = i - LEN;
        found = true;
      }
      if (cnt[i] > most) {
        most = cnt[i];
        many = i - LEN;
        second = false;
      } else if (cnt[i] == most && !second) {
        many = i - LEN;
        second = true;
      }
      if (min > i) {
        min = i;
      }
      max = i - LEN;
    }
  }
  avg = round(static_cast<double>(sum) / n);

  cout << avg << '\n';
  cout << mid << '\n';
  cout << many << '\n';
  cout << max - (min - LEN) << '\n';
  return 0;
}
