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
  std::vector<int> siz(n + 1), maxx(n + 1), vis(n + 1);
  int rt = 0, sum = n;
  maxx[0] = INT_MAX;
  auto getrt = [&](this auto &&self, int u, int p) -> void {
    siz[u] = 1;
    maxx[u] = 0;
    for (int v : g[u]) {
      if (!vis[v] && v != p) {
        self(v, u);
        siz[u] += siz[v];
        maxx[u] = std::max(maxx[u], siz[v]);
      }
    }
    maxx[u] = std::max(maxx[u], sum - siz[u]);
    if (maxx[u] < maxx[rt]) {
      rt = u;
    }
  };
  int pcnt = 0, qcnt = 0, psum = 0, qsum = 0;
  // p->向下一步走不到叶子且非叶子
  // q->父节点非叶子且父节点的兄弟节点非叶子
  std::vector<int> hasleaf(n + 1);
  auto work = [&](this auto &&self, int u, int p) -> void {
    if ()
    for (int v : g[u]) {
      if (!vis[v] && v != p) {
        self(v, u);
      }
    }
  };
  int ans = 0;
  auto dfz = [&](this auto &&self, int u, int p) -> void {
    vis[u] = 1;
    pcnt = qcnt = psum = qsum = 0;
    for (int v : g[u]) {
      if (!vis[v] && v != p) {
        work(v, u);
      }
    }
    for (int v : g[u]) {
      if (!vis[v] && v != p) {
        sum = siz[v];
        getrt(v, 0);
        self(rt, 0);
      }
    }
  };
  getrt(1, 0);
  dfz(rt, 0);
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