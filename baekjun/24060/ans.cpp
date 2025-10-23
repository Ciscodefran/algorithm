#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// NOTE: read_numbers 하는 방법
// NOTE: 람다의 반환 타입은 auto 입니다.
// [] 는 캡쳐 목록이고, () 는 매개변수 선언부 입니다.
auto read_numbers = [](int& n) {
  // NOTE: n 크기만큼 vector 정의하는 방법
  vector<int> v(n);
  for (int& x : v) cin >> x;
  return v;
};

void merge(vector<int>& v, int lo, int mid, int hi, int& cnt, int& t) {
  // NOTE: 병합정렬 구현 방법
  vector<int> buf(hi - lo + 1);
  int i = lo, j = mid + 1, k = 0;
  while (i <= mid && j <= hi) {
    buf[k++] = (v[i] <= v[j]) ? v[i++] : v[j++];
    if (cnt == t) {
      cout << buf[k - 1] << '\n';
    }
    cnt++;
  }
  while (i <= mid) {
    buf[k++] = v[i++];
    if (cnt == t) {
      cout << buf[k - 1] << '\n';
    }
    cnt++;
  }
  while (j <= hi) {
    buf[k++] = v[j++];
    if (cnt == t) {
      cout << buf[k - 1] << '\n';
    }
    cnt++;
  }
  // NOTE: move 함수는 <algorithm>의 영역이동 알고리즘 입니다.
  // 시그니쳐는 template<class InputIt, class OutputIt>
  // OutputIt move(InputIt first, InputIt last, OutputIt d_first);
  // move(buf.begin(), buf.end(), v.begin() + lo);
  copy_n(buf.begin(), buf.size(), v.begin() + lo);
}

void merge_sort(vector<int>& v, int lo, int hi, int& k, int& t) {
  if (lo >= hi) return;
  const int mid = (lo + hi) / 2;
  merge_sort(v, lo, mid, k, t);
  merge_sort(v, mid + 1, hi, k, t);
  merge(v, lo, mid, hi, k, t);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, t;
  cin >> n;
  cin >> t;
  vector<int> data = read_numbers(n);
  int k = 0;
  t--;
  merge_sort(data, 0, static_cast<int>(data.size()) - 1, k, t);
  if (t >= k) {
    cout << -1 << '\n';
  }
  return 0;
}
