#include <bits/stdc++.h>

int main() {
  std::string str;
  std::cin >> str;
  std::sort(str.begin(), str.end());
  std::reverse(str.begin(), str.end());
  for (auto ch : str) {
    std::cout << ch;
  }
}