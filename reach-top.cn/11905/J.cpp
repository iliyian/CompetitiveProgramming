#include <bits/stdc++.h>

int main() {
  std::string str;
  std::cin >> str;
  std::string aeiou = "aeiou";
  for (int i = 0; i < str.size(); i++) {
    if (aeiou.find(tolower(str[i])) == std::string::npos) {
      std::cout << str[i];
    }
  }
  return 0;
}