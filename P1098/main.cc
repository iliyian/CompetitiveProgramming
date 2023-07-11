#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;

int p1, p2, p3;

char transform(char c) {
  switch(p1) {
    case 1:
      return tolower(c);
    case 2:
      return toupper(c);
    case 3:
      return '*';
  }
}

int main() {
  string str;
  cin >> p1 >> p2 >> p3 >> str;
  int len = str.size();
  for (int i = 0; i < len; i++) {
    if (str[i] == '-' && i - 1 >= 0 && i + 1 < len) {
      char left = str[i-1], right = str[i+1];
      if (left == '-' || right == '-') {
        cout << str[i];
      }
      else if (left >= right) {
        cout << '-';
      } else if (isdigit(left) && isdigit(right)) {
        string s;
        for (int i = left+1; i < right; i++) {
          for (int j = 0; j < p2; j++) {
            s += p1 == 3 ? '*' : i;
          }
        }
        if (p3 == 2) reverse(s.begin(), s.end());
        cout << s;
      } else if (!isdigit(left) && !isdigit(right)) {
        string s;
        for (int i = left+1; i < right; i++) {
          for (int j = 0; j < p2; j++) {
            s += transform(i);
          }
        }
        if (p3 == 2) reverse(s.begin(), s.end());
        cout << s;
      } else {
        cout << '-';
      }
    } else {
      cout << str[i];
    }
  }
  return 0;
}