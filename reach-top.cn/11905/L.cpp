#include <bits/stdc++.h>

int main() {
  int n;
  std::cin >> n;
  for (int i = 1; i <= n; i++) {
    std::string str;
    std::cin >> str;
    int ans = 0;
    for (auto i : str) {
      ans += i - '0';
      ans %= 3;
    }
    std::cout << (ans ? "No" : "Yes") << '\n';
  }
  return 0;
}