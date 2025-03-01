#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, k;
  std::cin >> n >> k;
  auto get = [&](auto self, int x, int y) -> int {
    // std::cerr << x << ' ' << y << '\n';
    if (x == 0) return 1;
    if (x == 1) {
      return y == 1;
    };
    if (y > x) return 0;
    int hi = 62;
    while (x >> hi & 1 ^ 1) hi--;
    // std::cerr << hi << '\n';
    if (y > (1 << hi)) return self(self, x, y - (1 << hi));
    return self(self, x - (1 << hi), y);
  };
  for (int i = 1; i <= n; i++) {
    std::cout << get(get, n, i) * k << ' ';
  }
  std::cout << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  // int n = 100;
  // std::vector<std::vector<int>> ans(n + 1, std::vector<int>(n + 1));
  // ans[0][0] = ans[0][1] = 1;
  // for (int i = 1; i <= n; i++) {
  //   ans[i][1] = ans[i - 1][1], ans[i][i] = ans[i - 1][i - 1];
  //   for (int j = 2; j < i; j++) {
  //     ans[i][j] = ans[i - 1][j - 1] ^ ans[i - 1][j];
  //   }
  //   for (int j = 1; j <= i; j++) {
  //     std::cout << ans[i][j] << ' ';
  //   }
  //   std::cout << '\n';
  // }
  // return 0;

  int t = 1;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}