#include <bits/stdc++.h>
#include <cctype>

int main() {
  std::string str;
  getline(std::cin, str);
  for (auto i : str) {
    if (!isalpha(i)) {
      std::cout << char(i);
    } else if (isupper(i)) {
      std::cout << char(tolower(i));
    } else {
      std::cout << char(toupper(i));
    }
  }
  return 0;
}