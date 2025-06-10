// date: 2025-05-06 13:48:01
// tag: 根据主定理分析复杂度，然后发现是水题

#include <bits/stdc++.h>
#define int long long

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
  std::vector<int> vis(n + 1), dep(n + 1), pa(n + 1);
  int c = 0;
  auto get = [&](auto self, int u, int p) -> void {
    dep[u] = dep[p] + 1;
    pa[u] = p;
    if (dep[u] > dep[c] || dep[u] == dep[c] && u > c) {
      c = u;
    }
    for (int v : g[u]) {
      if (v != p && !vis[v]) {
        self(self, v, u);
      }
    }
  };
  std::queue<int> q;
  std::vector<std::array<int, 3>> ans;
  q.push(1);
  while (!q.empty()) {
    int u = q.front(); q.pop();
    if (vis[u]) continue;
    c = 0;
    get(get, u, 0);
    int d = c;
    c = 0;
    get(get, d, 0);
    vis[d] = 1;
    ans.push_back({dep[c], std::max(c, d), std::min(c, d)});
    // std::cerr << u << ' ' << c << ' ' << d << '\n';
    int cur = c;
    while (c != d) {
      vis[c] = 1;
      c = pa[c];
    }
    while (cur != d) {
      for (int v : g[cur]) {
        if (!vis[v]) {
          q.push(v);
        }
      }
      cur = pa[cur];
    }
  }
  std::sort(ans.begin(), ans.end(), std::greater<>());
  for (auto [d, x, y] : ans) {
    std::cout << d << ' ' << x << ' ' << y << ' ';
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