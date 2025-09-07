#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  std::vector<std::vector<int>> g(n + 1);
  for (int i = 2; i <= n; i++) {
    int x, y;
    std::cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  std::vector<int> dep(n + 1), pa(n + 1);
  auto dfs = [&](auto self, int u, int p) -> void {
    dep[u] = dep[p] + 1;
    pa[u] = p;
    for (int v : g[u]) {
      if (v != p) {
        self(self, v, u);
      }
    }
  };
  dfs(dfs, 1, 0);
  while (m--) {
    int op, x, y;
    std::cin >> op >> x >> y;
    if (op == 1) {
      int ans = 0;
      while (x != y) {
        if (dep[x] < dep[y]) std::swap(x, y);
        ans = std::max(ans, a[x]);
        x = pa[x];
      }
      ans = std::max(ans, a[x]);
      std::cout << ans << '\n';
    } else {
      for (int v : g[x]) {
        a[v] += y;
      }
    }
  }
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