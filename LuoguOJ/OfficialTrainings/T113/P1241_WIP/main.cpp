#include <bits/stdc++.h>
using namespace std;

bitset<1000> paired;

bool isLeft(char ch) {return ch == '(' || ch == '[';}
bool isRight(char ch) {return ch == ')' || ch == ']';}
bool topair(char a, char b) {return a == '(' && b == ')' || a == '[' && b == ']';}

int main() {
  string str;
  cin >> str;
  for (int i = str.size() - 1; i >= 0; i--) {
    if (isRight(str[i])) {
      for (int j = i - 1; j >= 0; j--) {
        if (isLeft(str[j])) {
          bool f = true;
          for (int k = j + 1; k < i; k++)
            if (topair(str[j], str[k])) {f = false; paired[j] = paired[k] = true; break;}
          if (f && topair(str[j], str[i]))
            paired[i] = paired[j] = true;
          if (paired[j]) break;
        }
      }
    }
  }
  for (int i = 0; i < str.size(); i++) {
    if (!paired[i]) {
      if (str[i] == '(' || str[i] == ')') cout << "()";
      else cout << "[]";
    } else cout << str[i];
  }
  return 0;
}