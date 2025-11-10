#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n = 11, x;
  string s;
  vector<vector<int>> v(n, vector<int>(n, 0));
  vector<vector<int>> r_cnt(3, vector<int>(3, 0));
  vector<vector<int>> r_sum(3, vector<int>(3, 0));

  for (int i = 1; i < n - 1; ++i) {
    for (int j = 1; j < n - 1; ++j) {
      cin >> x;
      v[i][j] = x;
      if (x == 0) {
        ++v[i][0];
        ++v[0][j];
        r_cnt[(i - 1) / 3][(j - 1) / 3]++;
      }
      v[i][n - 1] += x;
      v[n - 1][j] += x;
      r_sum[(i - 1) / 3][(j - 1) / 3] += x;
    }
  }

  auto fill_cell = [&](int a, int b, int val) {
    v[a][b] = val;
    v[a][n - 1] += val;
    v[n - 1][b] += val;
    r_sum[(a - 1) / 3][(b - 1) / 3] += val;
    --v[a][0];
    --v[0][b];
    --r_cnt[(a - 1) / 3][(b - 1) / 3];
  };

  bool changed = true;
  while (changed) {
    changed = false;

    for (int i = 1; i < n - 1 && !changed; ++i) {
      if (v[0][i] == 1) {
        for (int j = 1; j < n - 1; ++j) {
          if (v[j][i] == 0) {
            int r = 45 - v[n - 1][i];
            fill_cell(j, i, r);
            changed = true;
            break;
          }
        }
      } else if (v[i][0] == 1) {
        for (int j = 1; j < n - 1; ++j) {
          if (v[i][j] == 0) {
            int r = 45 - v[i][n - 1];
            fill_cell(i, j, r);
            changed = true;
            break;
          }
        }
      }
    }

    if (changed) continue;

    for (int bi = 0; bi < 3 && !changed; ++bi) {
      for (int bj = 0; bj < 3 && !changed; ++bj) {
        if (r_cnt[bi][bj] == 1) {
          int rr = 45 - r_sum[bi][bj];
          int start_i = bi * 3 + 1;
          int start_j = bj * 3 + 1;
          for (int a = start_i; a < start_i + 3 && !changed; ++a) {
            for (int b = start_j; b < start_j + 3; ++b) {
              if (v[a][b] == 0) {
                fill_cell(a, b, rr);
                changed = true;
                break;
              }
            }
          }
        }
      }
    }
  }

  for (int i = 1; i < n - 1; ++i) {
    for (int j = 1; j < n - 1; ++j) {
      s.append(to_string(v[i][j]));
      s.append(" ");
    }
    s.append("\n");
  }
  cout << s << endl;
  return 0;
}
