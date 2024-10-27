#include <bits/stdc++.h>

int main() {
  std::string str;
  std::cin >> str;
  int n = str.size();
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      std::cout << (i + j >= n - 1 ? str[(i + j + 1) % n] : ' ');
    }
    std::cout << '\n';
  }
  return 0;
}