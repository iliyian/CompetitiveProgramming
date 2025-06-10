#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<std::vector<std::array<int, 2>>> g(n + 1);
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
    int x, y, w;
    std::cin >> x >> y >> w;
    g[x].push_back({y, w});
    g[y].push_back({x, w});
  }
  maxx[0] = LLONG_MAX;
  std::vector<int> cur, cnt(n * 2 + 1), prv;
  auto dfs = [&](auto self, int u, int p, int d) -> void {
    cur.push_back(d);
    for (auto [v, w] : g[u]) {
      if (v != p && !vis[v]) {
        self(self, v, u, d + (w == 1 ? 1 : -1));
      }
    }
  };
  int ans = 0;
  auto work = [&](auto self, int u, int p) -> void {
    vis[u] = 1;
    for (auto [v, w] : g[u]) {
      if (!vis[v] && v != p) {
        dfs(dfs, v, u, 0);
        for (int i = 0; i < cur.size(); i++) {
          ans += cnt[-cur[i] + n];
        }
        while (!cur.empty()) {
          cnt[cur.back() + n]++;
          prv.push_back(cur.back());
          cur.pop_back();
        }
      }
    }
    while (!prv.empty()) {
      cnt[prv.back() + n]--;
      prv.pop_back();
    }
    for (auto [v, w] : g[u]) {
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