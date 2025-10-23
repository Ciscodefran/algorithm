#include <stdio.h>
#include <string.h>

#include <iostream>
#include <string>

// HACK: string 과 string.h 의 차이점은?
// INFO: <string> 헤더는 CPP 용 string 클래스를 제공하고,
// <string.h> 는 strlen, strcmp 등 C 스타일 문자열 함수를 제공한다.

int recursion(const char *s, int l, int r, int &i) {
  i++;
  if (l >= r)
    return 1;
  else if (s[l] != s[r])
    return 0;
  else
    return recursion(s, l + 1, r - 1, i);
}

// INFO: 메모리 복사 없이 문자열을 넘기는 방법
void isPalindrome(const char *s) {
  int i = 0;
  int n = recursion(s, 0, strlen(s) - 1, i);
  std::cout << n << ' ' << i << '\n';
}

int main() {
  int n = 0;
  std::cin >> n;
  std::string b;
  for (int i = 0; i < n; i++) {
    std::cin >> b;
    // HACK: string 의 첫번째 포인터를 반환하는 b.at(0) 은 왜 안되나
    // INFO: str.at(0) 과 str.c_str() 의 차이점은 at 은 char 한 개만 반환하고,
    // 포인터가 아닌데 반해, c_str 은 첫번째 포인터를 반환한다.
    isPalindrome(b.c_str());
  }
}
