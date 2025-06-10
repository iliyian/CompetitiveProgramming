// date: 2025-05-20 20:39:38
// tag: cf比较少见的出了点分治吧，树上log级别的东西好像点分治少不了

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<std::vector<int>> g(n + 1);
  std::vector<int> vis(n + 1), siz(n + 1), maxx(n + 1);
  int tot = n, rt = 0;
  auto getrt = [&](auto self, int u, int p) -> void {
    siz[u] = 1;
    maxx[u] = 0;
    for (int v : g[u]) {
      if (!vis[v] && v != p) {
        self(self, v, u);
        siz[u] += siz[v];
        maxx[u] = std::max(maxx[u], siz[v]);
      }
    }
    maxx[u] = std::max(maxx[u], tot - siz[u]);
    if (maxx[u] < maxx[rt]) {
      rt = u;
    }
  };
  for (int i = 2; i <= n; i++) {
    int x, y;
    std::cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  maxx[0] = LLONG_MAX;
  auto work = [&](auto self, int u, int p) -> void {
    vis[u] = 1;
    for (int v : g[u]) {
      if (!vis[v] && v != p) {
        
      }
    }
    for (int v : g[u]) {
      if (v != p && !vis[v]) {
        rt = 0;
        tot = siz[v];
        getrt(getrt, v, 0);
        self(self, rt, 0);
      }
    }
  };
  getrt(getrt, 1, 0);
  work(work, rt, 0);
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