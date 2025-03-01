// date: 2024-11-18 19:22:45
// tag: 点分治，树的重心

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<std::pair<int, int>>> g(n + 1);
  for (int i = 2; i <= n; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    g[x].push_back({y, w});
    g[y].push_back({x, w});
  }

  std::vector<int> vis(n + 1), dis(n + 1), siz(n + 1), prvdis;
  int rt = 0;
  auto calcdis = [&](auto self, int u, int p) -> void {
    if (dis[u] > 1e7) {
      return;
    }
    prvdis.push_back(dis[u]);
    for (auto [v, w] : g[u]) {
      if (v != p && !vis[v]) {
        dis[v] = dis[u] + w;
        self(self, v, u);
      }
    }
  };

  int sum = n;
  std::vector<int> maxx(n + 1);
  auto calcrt = [&](auto self, int u, int p) -> void {
    siz[u] = 1;
    maxx[u] = 0;
    for (auto [v, w] : g[u]) {
      if (v != p && !vis[v]) {
        self(self, v, u);
        siz[u] += siz[v];
        maxx[u] = std::max(maxx[u], siz[v]);
      }
    }
    maxx[u] = std::max(maxx[u], sum - siz[u]);
    if (maxx[u] < maxx[rt]) {
      rt = u;
    }
  };

  std::vector<int> ans(m + 1), q(m + 1), ok(1e7 + 10), oked;
  int tot = 0;
  auto dfs = [&](auto self, int u, int p) -> void {
    tot++;
    ok[0] = true;
    vis[u] = true;
    oked.push_back(u);
    for (auto [v, w] : g[u]) {
      if (v != p && !vis[v]) {
        dis[v] = w;
        calcdis(calcdis, v, u);
        for (int i = 1; i <= m; i++) {
          for (int j : prvdis) {
            if (q[i] >= j) {
              ans[i] |= ok[q[i] - j];
            }
          }
        }
        while (!prvdis.empty()) {
          oked.push_back(prvdis.back());
          ok[prvdis.back()] = true;
          prvdis.pop_back();
        }
      }
    }
    while (!oked.empty()) ok[oked.back()] = false, oked.pop_back();
    for (auto [v, w] : g[u]) {
      if (v != p && !vis[v]) {
        rt = 0;
        sum = siz[v];
        calcrt(calcrt, v, u);
        self(self, rt, 0);
      }
    }
  };

  for (int i = 1; i <= m; i++) {
    std::cin >> q[i];
  }
  rt = 0;
  maxx[0] = INT_MAX;
  calcrt(calcrt, 1, 0);
  dfs(dfs, rt, 0);
  for (int i = 1; i <= m; i++) {
    std::cout << (ans[i] ? "AYE" : "NAY") << '\n';
  }
  // std::cout << tot << '\n';
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  // std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}