// 模拟水题，真不知道为什么很久之前很久都没做出来

#include <bits/stdc++.h>
using namespace std;

bool left(char c) {
  return c == '(' || c == '[';
}

bool right(char c) {
  return !left(c);
}

bool pai(char a, char b) {
  return a == '(' && b == ')' || a == '[' && b == ']';
}

bitset<100> paired;

int main() {
  string str;
  cin >> str;
  for (int i = 0; i < str.size(); i++) {
    if (right(str[i])) {
      for (int j = i - 1; j >= 0; j--) {
        if (left(str[j]) && !paired[j]) {
          if (pai(str[j], str[i])) {
            paired[i] = paired[j] = true;
          }
          break;
        }
      }
    }
  }
  for (int i = 0; i < str.size(); i++) {
    if (!paired[i]) {
      if (left(str[i])) cout << str[i] << (str[i] == '(' ? ')' : ']');
      else cout << (str[i] == ')' ? '(' : '[') << str[i];
    } else
      cout << str[i];
  }
  return 0;
}