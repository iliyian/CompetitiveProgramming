// date: 2025-04-07 23:59:04
// tag: 十分精致的一道换根树形博弈dp

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, q;
  std::cin >> n >> q;
  std::vector<std::vector<int>> g(n + 1);
  for (int i = 2; i <= n; i++) {
    int x, y;
    std::cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  std::vector<int> f(n + 1), h(n + 1), cnt(n + 1);
  auto dfs = [&](auto self, int u, int p) -> void {
    for (int v : g[u]) {
      if (v != p) {
        self(self, v, u);
        if (!f[v]) {
          f[u] = 1;
          cnt[u]++;
        }
      }
    }
  };
  // h[0] = 1;
  auto dfs2 = [&](auto self, int u, int p) -> void {
    for (int v : g[u]) {
      if (v != p) {
        if (!h[u] && cnt[u] < 2 && (!f[v] || cnt[u] != 1)) {
          h[v] = 1;
        }
        self(self, v, u);
      }
    }
  };
  dfs(dfs, 1, 0);
  dfs2(dfs2, 1, 0);
  while (q--) {
    int x;
    std::cin >> x;
    std::cout << (f[x] || h[x] ? "Ron" : "Hermione") << '\n';
    // std::cerr << x << ' ' << f[x] << ' ' << h[x] << '\n';
  }
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  // std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}