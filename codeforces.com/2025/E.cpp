// date: 2024-12-06 14:17:11
// tag: 计数dp，还行，挺有意思，关键在于找到对称性，然后加法原理，乘法原理

#include <bits/stdc++.h>
#define int long long

constexpr int mod = 998244353;
constexpr int N = 500;

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<int>> f(m + 1, std::vector<int>(m + 2));
  f[0][0] = 1;
  for (int i = 1; i <= m; i++) {
    f[i][0] = f[i - 1][1];
    f[i][0] %= mod;
    for (int j = 1; j <= i; j++) {
      f[i][j] += f[i - 1][j - 1] + f[i - 1][j + 1];
      f[i][j] %= mod;
    }
  }
  if (n == 1) {
    std::cout << f[m][0] << '\n';
    return;
  }
  int ans = 0;
  std::vector<std::vector<int>> g(n + 1, std::vector<int>(m + 1));
  for (int i = 0; i <= m; i++) {
    g[2][i] = f[m][i];
  }
  for (int i = 3; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      for (int k = 0; k <= j; k++) {
        g[i][j] += g[i - 1][k] * f[m][j - k] % mod;
        g[i][j] %= mod;
      }
    }
  }
  for (int i = 0; i <= m; i++) {
    ans += f[m][i] * g[n][i] % mod;
    ans %= mod;
  }
  std::cout << ans << '\n';
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  // std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}