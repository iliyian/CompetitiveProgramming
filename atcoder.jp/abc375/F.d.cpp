#include <bits/stdc++.h>
#define int long long

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  freopen("F.in", "w", stdout);
  int n = 300;
  int m = n * (n - 1) / 2;
  int q = 300;
  std::cout << n << ' ' << m << ' ' << q << '\n';
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      std::cout << i << ' ' << j << ' ' << (int)1e5 << '\n';
    }
  }
  for (int i = 1; i <= q; i++) {
    std::cout << 1 << ' ' << i << '\n';
  }
  return 0;
}