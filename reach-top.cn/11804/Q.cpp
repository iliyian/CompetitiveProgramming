#include <bits/stdc++.h>
#define int long long

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  std::cin >> n;
  for (int i = 1; i <= n * 2 - 1; i++) {
    for (int j = 1; j <= std::abs(n - i); j++) {
      std::cout << ' ';
    }
    for (int j = 1; j <= n * 2 - 1 - std::abs(n - i) * 2; j++) {
      std::cout << j;
    }
    for (int j = 1; j <= std::abs(n - i); j++) {
      std::cout << ' ';
    }
    std::cout << '\n';
  }
  return 0;
}