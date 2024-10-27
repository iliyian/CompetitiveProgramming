#include <bits/stdc++.h>

int main() {
  std::string str;
  std::cin >> str;
  int n = str.size();
  bool f = false;
  for (char i : str) {
    if (isdigit(i)) {
      if (i != '0') f = true;
      if (f) {
        std::cout << i;
      }
    }
  }
  return 0;
}