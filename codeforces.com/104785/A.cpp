#include <bits/stdc++.h>

signed main() {
  freopen("A.in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n, w;
  std::cin >> n >> w;
  if (w >= n) {
    for (int i = 1; i <= n / 2; i++) {
      std::cout << w - i + 1 << ' ' << i << '\n';
    }
    for (int i = n / 2 + 1; i <= n; i++) {
      std::cout << w + i - 1 << ' ' << i << '\n';
    }
  } else {
    for (int i = 1; i <= n / 2; i++) {
      std::cout << w + i - 1 << ' ' << i << '\n';
    }
    for (int i = n / 2 + 1; i <= n; i++) {
      std::cout << w - i + 1 << ' ' << i << '\n';
    }
  }
  return 0;
}