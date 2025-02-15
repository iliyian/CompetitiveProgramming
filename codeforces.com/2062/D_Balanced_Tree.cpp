#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> l(n + 1), r(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> l[i] >> r[i];
  }
  std::vector<std::vector<int>> g(n + 1);
  for (int i = 2; i <= n; i++) {
    int x, y;
    std::cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  std::vector<int> f(n + 1);
  int sum = 0;
  auto dfs = [&](auto self, int u, int p) -> void {
    int mx = l[u];
    for (int v : g[u]) {
      if (v != p) {
        self(self, v, u);
        mx = std::max(mx, f[v]);
      }
    }
    f[u] = std::min(mx, r[u]);
    for (int v : g[u]) if (v != p) sum += std::max(0ll, f[v] - f[u]);
  };
  dfs(dfs, 1, 0);
  std::cout << f[1] + sum << '\n';
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