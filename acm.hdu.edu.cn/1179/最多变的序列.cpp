#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  std::vector<std::vector<int>> f(n + 1, std::vector<int>(n + 1)), g(n + 1, std::vector<int>(n + 1));
  std::ranges::fill(g[0], 1);
  for (int i = 1; i <= n; i++) {
    int mn = a[i];
    f[i][i] = g[i - 1][i];
    for (int j = i - 1; j >= 1; j--) {
      if (a[j] < mn) {
        mn = a[j];
        f[i][j] = g[i - 1][j];
      }
    }
    mn = a[i];
    for (int j = i + 1; j <= n; j++) {
      if (a[j] < mn) {
        mn = a[j];
        f[i][j] = g[i - 1][j];
      }
    }
    for (int j = 1; j <= n; j++) {
      g[i][j] = (g[i][j - 1] + f[i][j]) % 998244353;;
    }
  }
  std::cout << g[n][n] << '\n';
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