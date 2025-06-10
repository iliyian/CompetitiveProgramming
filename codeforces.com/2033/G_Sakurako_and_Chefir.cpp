// date: 2025-04-28 20:08:02
// tag: 树上倍增优化dp

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<std::vector<int>> g(n + 1);
  for (int i = 1; i <= n - 1; i++) {
    int x, y;
    std::cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  std::vector<std::vector<int>> pa(21, std::vector<int>(n + 1));
  std::vector<std::vector<int>> f(21, std::vector<int>(n + 1));
  std::vector<int> dep(n + 1), maxdep(n + 1);
  auto dfs = [&](auto self, int u, int p) -> void {
    dep[u] = dep[p] + 1;
    maxdep[u] = dep[u];
    pa[0][u] = p;
    for (int i = 1; i <= 20; i++) {
      pa[i][u] = pa[i - 1][pa[i - 1][u]];
    }
    for (int v : g[u]) {
      if (v != p) {
        self(self, v, u);
        maxdep[u] = std::max(maxdep[u], maxdep[v]);
      }
    }
  };
  auto dfs2 = [&](auto self, int u, int p) -> void {
    std::multiset<std::pair<int, int>, std::greater<>> s;
    for (int v : g[u]) {
      if (v != p) {
        s.insert({maxdep[v], v});
      }
    }
    for (int v : g[u]) {
      if (v != p) {
        s.erase({maxdep[v], v});
        if (!s.empty()) {
          f[0][v] = s.begin()->first - dep[u] + 1;
        }
        s.insert({maxdep[v], v});
      }
    }
    for (int v : g[u]) {
      if (v != p) {
        self(self, v, u);
      }
    }
  };
  dfs(dfs, 1, 0);
  dfs2(dfs2, 1, 0);
  for (int i = 1; i <= 20; i++) {
    for (int j = 1; j <= n; j++) {
      f[i][j] = std::max(f[i - 1][j], (1 << (i - 1)) + f[i - 1][pa[i - 1][j]]);
    }
  }
  int q;
  std::cin >> q;
  while (q--) {
    int u, k;
    std::cin >> u >> k;
    int cur = 0, ans = maxdep[u] - dep[u];
    for (int i = 20; i >= 0; i--) {
      if (pa[i][u] && cur + (1 << i) <= k) {
        ans = std::max(ans, cur + f[i][u]);
        cur += 1 << i;
        u = pa[i][u];
      }
    }
    ans = std::max(ans, cur);
    std::cout << ans << ' ';
  }
  std::cout << '\n';
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