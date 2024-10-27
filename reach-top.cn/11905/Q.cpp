#include <bits/stdc++.h>
#include <cctype>

int main() {
  std::string str;
  std::cin >> str;
  for (int i = 0; i < str.size(); i++) {
    for (int j = 0; j <= i; j++) {
      std::cout << str[i];
    }
  }
  return 0;
}