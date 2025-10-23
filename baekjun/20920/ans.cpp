#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

const int MAX_N = 100000;  // 단어 개수
const int MAX_M = 10;      // 단어 길이의 기준

#define pp pair<string, int>  // HACK: 이게 뭔지..

bool cmp(const pp& a, const pp& b) {  // HACK: cmp 작성하는 방법, 시그니쳐
  if (a.second == b.second && a.first.length() == b.first.length()) {
    // 알파벳 사전 순으로 앞에 있는 단어일수록 앞에 배치한다
    return a.first < b.first;  // HACK: 사전 순 비교 하는 방법
  } else if (a.second == b.second) {
    // 해당 단어의 길이가 길수록 앞에 배치한다.
    return a.first.length() > b.first.length();
  } else {
    // 자주 나오는 단어일수록 앞에 배치한다.
    return a.second > b.second;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int m, n;
  string word;
  map<string, int> word_container;
  cin >> n;
  cin >> m;
  for (int i = 0; i < n; i++) {
    cin >> word;
    if (word.length() < m) {
      continue;
    }
    if (word_container.find(word) != word_container.end()) {
      word_container[word] += 1;
    } else {
      word_container.insert({word, 1});
    }
  }
  vector<pp> vec(word_container.begin(),
                 word_container.end());  // HACK: map -> vector
  sort(vec.begin(), vec.end(), cmp);  // HACK: sort 메소드 함수 시그니쳐와 헤더
  for (pp& v : vec) {                 // HACK: pp, pp& 의 차이
    cout << v.first << '\n';
  }
  return 0;
}
