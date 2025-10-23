#include <ios>
#include <iostream>
#include <map>
#include <queue>
#include <string>
using namespace std;

#define pair <string, int> pp;

struct WordInfo {
  string word;
  int freq;

  bool operator<(const WordInfo& other) const {
    if (freq != other.freq) return freq < other.freq;
    if (word.length() != other.word.length())
      return word.length() < other.word.length();
    return word > other.word;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int m, n;
  string buf;
  cin >> n;
  cin >> m;
  map<string, int> dic;
  for (int i = 0; i < n; i++) {
    cin >> buf;
    if (buf.length() < m) {
      continue;
    }
    if (dic.find(buf) != dic.end()) {
      dic[buf] += 1;
    } else {
      dic.insert({buf, 1});
    }
  }
  priority_queue<WordInfo> pq;
  for (auto& d : dic) {
    pq.push({d.first, d.second});
  }
  while (!pq.empty()) {
    cout << pq.top().word << '\n';
    pq.pop();
  }
  return 0;
}
