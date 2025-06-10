#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<std::vector<std::array<int, 3>>> g(n + 1);
  std::vector<std::vector<int>> h(n + 1);
  for (int i = 2; i <= n; i++) {
    int x, y, p, q;
    std::cin >> x >> y >> p >> q;
    g[x].push_back({y, p, q});
    g[y].push_back({x, q, p});
  }
  int s, t;
  std::cin >> s >> t;
  std::vector<int> f(n + 1), pa(n + 1);
  auto dfs = [&](auto self, int u, int p) -> void {
    pa[u] = p;
    for (auto [v, w1, w2] : g[u]) {
      if (v != p) {
        self(self, v, u);
        f[u] += std::max(0ll, f[v] + w1 + w2);
      }
    }
  };
  dfs(dfs, t, 0);
  int ans = f[s];
  if (s == t) {
    std::cout << ans << '\n';
    return;
  }
  while (s != t) {
    int old = s;
    s = pa[s];
    for (auto [v, w1, w2] : g[s]) {
      if (v != pa[s] && v != old) {
        ans += std::max(0ll, f[v] + w1 + w2);
      }
      if (v == old) {
        ans += w2;
      }
    }
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