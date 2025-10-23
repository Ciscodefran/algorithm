#include <algorithm>
#include <vector>

using namespace std;

void merge(vector<int>& v, int lo, int mid, int hi) {
  vector<int> buf(hi - lo + 1);
  int i = lo, j = mid + 1, k = 0;
  while (i <= mid && j <= hi) buf[k++] = (v[i] <= v[j]) ? v[i++] : v[j++];
  while (i <= mid) buf[k++] = v[i++];
  while (j <= hi) buf[k++] = v[j++];
  copy_n(buf.begin(), buf.size(), v.begin() + lo);
}

void merge_sort(vector<int>& v, int lo, int hi) {
  if (lo >= hi) return;
  const int mid = (lo + hi) / 2;
  merge_sort(v, lo, mid);
  merge_sort(v, mid + 1, hi);
  merge(v, lo, mid, hi);
}

int main() {
  merge_sort(arr, 0, static_cast<int>(arr.size()) - 1);
  return 0;
}

int change_val(int& p) {}
