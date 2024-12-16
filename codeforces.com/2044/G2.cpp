// date: 2024-12-16 22:55:13
// tag: 基环树森林dp

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  std::vector<int> isloop(n + 1);
  std::vector<std::vector<int>> g(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    g[a[i]].push_back(i);
  }
  std::vector<int> dep(n + 1), pa(n + 1);
  auto dfs = [&](auto self, int u, int p) -> void {
    pa[u] = p;
    dep[u] = dep[p] + 1;
    for (int v : g[u]) {
      if (!dep[v]) {
        self(self, v, u);
      } else if (dep[v] < dep[u]) {
        for (int i = u;; i = pa[i]) {
          isloop[i] = 1;
          if (i == v) {
            break;
          }
        }
      }
    }
  };
  for (int i = 1; i <= n; i++) {
    if (!dep[i]) { // 基环树往往以基环树森林的形式出现
      dfs(dfs, i, 0);
    }
  }
  // for (int i = 1; i <= n; i++) {
  //   std::cout << isloop[i] << " \n"[i == n];
  // }
  std::vector<int> siz(n + 1);
  int maxsiz = 0;
  auto dfs2 = [&](auto self, int u) -> void {
    siz[u] = 1;
    for (int v : g[u]) {
      if (!isloop[v]) {
        self(self, v);
        siz[u] += siz[v];
      }
    }
    maxsiz = std::max(maxsiz, siz[u]);
  };
  for (int i = 1; i <= n; i++) {
    if (isloop[i]) {
      dfs2(dfs2, i);
    }
  }
  std::cout << maxsiz + 1 << '\n';
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}