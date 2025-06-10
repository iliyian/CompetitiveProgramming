#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<std::vector<int>> a(n + 1, std::vector<int>(n + 1));
  std::vector<std::array<int, 2>> f(n + 1, {LLONG_MAX / 3, LLONG_MAX / 3});
  std::vector<std::array<int, 2>> g(n + 1, {LLONG_MAX / 3, LLONG_MAX / 3});
  f[0][0] = f[0][1] = 0;
  g[0][0] = g[0][1] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      std::cin >> a[i][j];
    }
  }
  std::vector<int> r(n + 1), c(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> r[i];
  }
  for (int i = 1; i <= n; i++) {
    std::cin >> c[i];
  }
  auto checkr = [&](int i, int d) {
    if (i == 0) return false;
    for (int j = 1; j <= n; j++) {
      if (a[i][j] + d == a[i + 1][j]) {
        return true;
      }
    }
    return false;
  };
  auto checkc = [&](int j, int d) {
    if (j == 0) return false;
    for (int i = 1; i <= n; i++) {
      if (a[i][j] + d == a[i][j + 1]) {
        return true;
      }
    }
    return false;
  };
  for (int i = 1; i <= n; i++) {
    if (!checkr(i - 1, 0)) {
      f[i][0] = std::min(f[i][0], f[i - 1][0]);
    }
    if (!checkr(i - 1, 1)) {
      f[i][0] = std::min(f[i][0], f[i - 1][1]);
    }
    if (!checkr(i - 1, -1)) {
      f[i][1] = std::min(f[i][1], f[i - 1][0] + r[i]);
    }
    if (!checkr(i - 1, 0)) {
      f[i][1] = std::min(f[i][1], f[i - 1][1] + r[i]);
    }
  }
  for (int i = 1; i <= n; i++) {
    if (!checkc(i - 1, 0)) {
      g[i][0] = std::min(g[i][0], g[i - 1][0]);
    }
    if (!checkc(i - 1, 1)) {
      g[i][0] = std::min(g[i][0], g[i - 1][1]);
    }
    if (!checkc(i - 1, -1)) {
      g[i][1] = std::min(g[i][1], g[i - 1][0] + c[i]);
    }
    if (!checkc(i - 1, 0)) {
      g[i][1] = std::min(g[i][1], g[i - 1][1] + c[i]);
    }
  }
  if (std::min(f[n][0], f[n][1]) == LLONG_MAX / 3 || std::min(g[n][0], g[n][1]) == LLONG_MAX / 3) {
    std::cout << -1 << '\n';
    return;
  }
  std::cout << std::min(f[n][0], f[n][1]) + std::min(g[n][0], g[n][1]) << '\n';
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