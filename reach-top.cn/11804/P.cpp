#include <bits/stdc++.h>
#define int long long

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  char c;
  std::cin >> c >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n - i; j++) {
      std::cout << ' ';
    }
    for (int j = 1; j <= i; j++) {
      std::cout << c;
    }
    std::cout << ' ';
    for (int j = 1; j <= i; j++) {
      std::cout << c;
    }
    for (int j = 1; j <= n - i; j++) {
      std::cout << ' ';
    }
    std::cout << '\n';
  }
  return 0;
}