#include <bits/stdc++.h>
#define int long long

constexpr int mod = 1e9 + 7;
constexpr int N = 5e5;

std::vector<int> inv(N + 1), fac(N + 1), invfac(N + 1);

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1), b(n + 1), w(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    std::cin >> b[i];
  }
  for (int i = 1; i <= n; i++) {
    std::cin >> w[i];
  }
  std::vector<int> ans(n + 1), ok(n + 1);
  std::vector<std::vector<int>> g(n + 1);
  for (int i = 1; i <= n; i++) {
    if (a[i] < a[b[i]]) {
      ans[i] = a[i] + w[i];
      ans[i] %= mod;
      ok[i] = true;
    } else if (a[i] >= a[b[i]] + w[b[i]]) {
      ans[i] = a[i];
    } else {
      ans[i] = a[i];
      if (i != b[i]) {
        g[b[i]].push_back(i);
        // in[i]++; 
      }
    }
  }
  std::vector<int> vis(n + 1);
  auto dfs = [&](auto self, int u, int p, int dep) -> void {
    if (vis[u]) return;
    vis[u] = true;
    if (dep >= 2) {
      ans[u] += w[u] * invfac[dep] % mod;
      ans[u] %= mod;
    }
    for (int v : g[u]) {
      if (v != p) {
        self(self, v, u, dep + 1);
      }
    }
  };
  for (int i = 1; i <= n; i++) {
    if (ok[i]) {
      dfs(dfs, i, 0, 1);
    }
  }
  for (int i = 1; i <= n; i++) {
    std::cout << ans[i] % mod << " \n"[i == n];
  }
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  fac[0] = fac[1] = inv[1] = invfac[0] = invfac[1] = 1;
  for (int i = 2; i <= N; i++) {
    inv[i] = (mod - mod / i) * inv[mod % i] % mod;
    fac[i] = i * fac[i - 1] % mod;
    invfac[i] = inv[i] * invfac[i - 1] % mod;
  }

  int t = 1;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}