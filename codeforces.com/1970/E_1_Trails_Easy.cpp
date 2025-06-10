#include <bits/stdc++.h>
#define int long long

constexpr int mod = 1e9 + 7;

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<int>> f(m + 1, std::vector<int>(n + 1));
  f[0][1] = 1;
  std::vector<int> s(n + 1), l(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> s[i];
  }
  for (int i = 1; i <= n; i++) {
    std::cin >> l[i];
    s[i] += l[i];
    s[i] %= mod;
  }
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      for (int k = 1; k <= n; k++) {
        f[i][j] += f[i - 1][k] * ((s[j] * s[k] % mod - l[j] * l[k] % mod + mod) % mod) % mod;
        f[i][j] %= mod;
      }
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += f[m][i];
    ans %= mod;
  }
  std::cout << ans << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  // std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}