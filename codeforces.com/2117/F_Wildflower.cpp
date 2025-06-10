#include <bits/stdc++.h>
#define int long long

constexpr int mod = 1e9 + 7;

int qpow(int a, int b) {
  int ans = 1;
  while (b) {
    if (b & 1) ans = ans * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return ans;
}

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
  int a = 0, b = 0, c = 0;
  bool f = true;
  std::vector<int> dep(n + 1);
  auto dfs = [&](auto self, int u, int p) -> void {
    dep[u] = dep[p] + 1;
    if (g[u].size() == 3 || u == 1 && g[u].size() == 2) {
      c = u;
    }
    if (u != 1 && g[u].size() == 1) {
      if (!a) a = u;
      else if (!b) b = u;
      else f = false;
      return;
    }
    for (int v : g[u]) {
      if (v != p) {
        self(self, v, u);
      }
    }
  };
  dfs(dfs, 1, 0);
  if (!f) {
    std::cout << 0 << '\n';
    return;
  }
  if (!b) {
    std::cout << qpow(2, n) << '\n';
    return;
  }
  if (dep[a] == dep[b]) {
    std::cout << qpow(2, dep[c] + 1) << '\n';
    return;
  }
  int ans = qpow(2, dep[c]) * ((qpow(2, std::abs(dep[a] - dep[b])) + qpow(2, std::abs(dep[a] - dep[b]) - 1)) % mod) % mod;
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