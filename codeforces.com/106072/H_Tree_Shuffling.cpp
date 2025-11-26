#include <bits/stdc++.h>
#define int long long

constexpr int mod = 998244353;

void solve() {
  int n;
  std::cin >> n;
  std::vector<std::vector<int>> g(n + 1);
  for (int i = 2; i <= n; i++) {
    int x, y;
    std::cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  std::vector<int> fac(n + 1);
  fac[0] = 1;
  for (int i = 1; i <= n; i++) {
    fac[i] = fac[i - 1] * i % mod;
  }
  int s = -1, ans = 0;
  auto dfs = [&](auto self, int u, int p, int len) -> void { 
    if (u > s) {
      ans += fac[len];
      ans %= mod;
      ans -= fac[len - 1] * 2 % mod;
      ans = (ans + mod) % mod;
      ans += fac[len - 2];
      ans %= mod;
    }
    for (int v : g[u]) {
      if (v != p) {
        self(self, v, u, len + 1);
      }
    }
  };
  for (int i = 1; i <= n; i++) {
    s = i;
    dfs(dfs, i, 0, 1);
  }
  std::cout << (ans + 1) % mod << '\n';
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