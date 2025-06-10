#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<int>> a(n + 1, std::vector<int>(m + 1));
  std::vector<std::vector<int>> pre(n + 1, std::vector<int>(m + 2));
  std::vector<std::vector<int>> suf(n + 1, std::vector<int>(m + 2));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      std::cin >> a[i][j];
      pre[i][j] = std::max(pre[i][j - 1], a[i][j]);
    }
    for (int j = m; j >= 1; j--) {
      suf[i][j] = std::max(suf[i][j + 1], a[i][j]);
    }
  }
  int ans = 0;
  for (int j = 1; j <= m; j++) {
    std::vector<std::vector<std::array<int, 2>>> f(n + 1, std::vector<std::array<int, 2>>(n + 1, {LLONG_MIN / 3, LLONG_MIN / 3}));
    f[0][0][0] = 0;
    for (int i = 1; i <= n; i++) {
      for (int k = 0; k <= i; k++) {
        if (k > 0) {
          f[i][k][1] = std::max(f[i - 1][k - 1][1], f[i - 1][k - 1][0]) + a[i][j];
        }
        f[i][k][0] = std::max(f[i - 1][k][1], f[i - 1][k][0]) + std::max(pre[i][j - 1], suf[i][j + 1]);
      }
    }
    int res = 0;
    for (int k = n / 2 + 1; k <= n; k++) {
      res = std::max({f[n][k][1], f[n][k][0], res});
    }
    ans = std::max(ans, res);
  }
  std::cout << ans << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int t = 1;
  std::cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}