#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, x, y;
  std::cin >> n >> x >> y;
  if (x + 1 == y) {
    for (int i = 1; i <= n; i++) {
      if (i == n && i % 2) {
        std::cout << 2 << ' ';
      } else {
        std::cout << i % 2 << ' ';
      }
    }
    std::cout << '\n';
    return;
  }
  std::vector<int> ans(n + 1);
  if (n % 2 == 0) {
    if (x % 2 == y % 2) {
      for (int i = 1; i <= n; i++) {
        if (i == x) std::cout << 2 << ' ';
        else if (i == y) std::cout << 1 << ' ';
        else {
          std::cout << (std::abs(i - x) & 1 ^ 1) << ' ';
        }
      }
      std::cout << '\n';
    } else {
      for (int i = 1; i <= n; i++) {
        std::cout << i % 2 << ' ';
      }
      std::cout << '\n';
    }
  } else {
    ans[x] = 2;
    int cnt = n - 1;
    for (int i = x + 1; cnt--; i = i % n + 1) {
      ans[i] = cnt % 2;
    }
    for (int i = 1; i <= n; i++) {
      std::cout << ans[i] << ' ';
    }
    std::cout << '\n';
  }
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}