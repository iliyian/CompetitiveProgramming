#include <bits/stdc++.h>
#define int long long

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n, m;
  char c;
  std::cin >> n >> m >> c;
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= i - 1; j++) {
      std::cout << ' ';
    }
    for (int j = 1; j <= n; j++) {
      std::cout << c;
    }
    std::cout << '\n';
  }
  return 0;
}