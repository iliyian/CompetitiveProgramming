#include <bits/stdc++.h>
#include <cctype>

int main() {
  std::string str;
  std::cin >> str;
  if (str.size() < 8 || str.size() > 20) {
    std::cout << -1 << '\n';
    return 0;
  }
  for (int i = 0; i < str.size(); i++) {
    if (!isdigit(str[i])) {
      std::cout << 0 << '\n';
      return 0;
    }
  }
  std::cout << -2 << '\n';
  return 0;
}