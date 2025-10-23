#include <iostream>
#include <set>
using namespace std;

const string word = "ChongChong";

int main() {
  int n;
  string front, back;
  set<string> s;
  cin >> n;
  s.insert(word);
  for (int i = 0; i < n; i++) {
    cin >> front;
    cin >> back;
    if ((s.find(front) != s.end()) || (s.find(back) != s.end())) {
      s.insert(front);
      s.insert(back);
    }
  }
  cout << s.size();
  return 0;
}
