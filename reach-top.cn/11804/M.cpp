#include <bits/stdc++.h>
#define int long long

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  char x;
  int n;
  std::cin >> x >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n - i; j++) {
      std::cout << ' ';
    }
    for (int j = 1; j <= i * 2 - 1; j++) {
      std::cout << x;
    }
    for (int j = 1; j <= n - i; j++) {
      std::cout << ' ';
    }
    std::cout << '\n';
  }
  return 0;
}