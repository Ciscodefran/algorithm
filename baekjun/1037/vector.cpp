#include <cassert>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

int find_n(const vector<int>& vec) {
  int min = INT_MAX;
  int max = INT_MIN;
  for (int i : vec) {
    if (i < min) min = i;
    if (i > max) max = i;
  }
  return min * max;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  assert(find_n({4, 2}) == 8);
  assert(find_n({2}) == 4);
  assert(find_n({3, 4, 2, 12, 6, 8}) == 24);
  assert(find_n({14, 26456, 2, 28, 13228, 3307, 7, 23149, 8, 6614, 46298, 56, 4,
                 92596}) == 185192);
  cout << "Tested";
  // int s, b;
  // cin >> s;
  // vector<int> v = {};
  // for (int i = 0; i < s; i++) {
  //   cin >> b;
  //   v.push_back(b);
  // }
  // cout << find_n(v) << '\n';
  return 0;
}
