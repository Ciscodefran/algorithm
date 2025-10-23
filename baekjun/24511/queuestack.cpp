#include <iostream>
#include <list>

using namespace std;

// mem 1024;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, b;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  list<int> lst;
  for (int i = 0; i < n; i++) {
    cin >> b;
    if (arr[i] == 0) {
      lst.push_back(b);
    }
  }
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> b;
    lst.push_front(b);
    cout << lst.back() << ' ';
    lst.pop_back();
  }
  return 0;
}
