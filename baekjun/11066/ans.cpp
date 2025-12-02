#include <iostream>
#include <vector>
using namespace std;
int sum;
int cost(vector<int>& v, int s, int e) {
  if (e == s) {
    return v[e];
  }
  if (e - s == 1) {
    sum += v[s] + v[e];
    return v[s] + v[e];
  }
  if ((e - s) % 2 == 0) {
    int mid = (e - s) / 2;
    return cost(v, s, s + mid) + cost(v, s + mid + 1, e);
  } else {
    return cost(v, s, e - 1) + v[e];
  }
}

int test() {
  int k;
  cin >> k;
  vector<int> v(k);
  sum = 0;
  for (int i = 0; i < k; ++i) {
    cin >> v[i];
  }
  cost(v, 0, k - 1);
  return sum;
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    cout << test() << '\n';
  }
  return 0;
}
