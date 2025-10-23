#include <iostream>
#include <map>
#include <set>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  string b;
  cin >> n;
  map<string, int> m;
  set<string> s;
  for (int i = 0; i < n; i++) {
    cin >> b;
    if (b.compare("ENTER") == 0) {
      s.clear();
      continue;
    }
    if (s.find(b) != s.end()) {
      continue;
    } else {
      s.insert(b);
      auto key = m.find(b);
      if (key != m.end()) {
        key->second++;
      } else {
        m.insert({b, 1});
      }
    }
  }
  int sum = 0;
  for (auto i = m.begin(); i != m.end(); i++) {
    sum += i->second;
  }
  cout << sum << '\n';
  return 0;
}
