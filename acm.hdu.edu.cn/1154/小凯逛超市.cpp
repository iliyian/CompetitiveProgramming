#include <bits/stdc++.h>
#define int long long

constexpr int mod = 1e9 + 7;

void solve() {
  int n, m, V;
  std::cin >> n >> m >> V;
  // std::vector<std::vector<std::vector<int>>> f(n + 1, std::vector<std::vector<int>>(V + 1, std::vector<int>(m + 1)));
  std::vector<std::vector<int>> f(V + 1, std::vector<int>(m + 1));
  std::vector<int> g(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> g[i];
  }
  f[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= V; j++) {
      for (int k = 0; k <= m; k++) {
        if (j >= g[i] && k > 0) {
          f[j][k] += f[j - g[i]][k - 1];
          f[j][k] %= mod;
        }
      }
    }
  }
  int ans = 0;
  for (int i = 0; i <= V; i++) {
    ans += f[i][m];
    ans %= mod;
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