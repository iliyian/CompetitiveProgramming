// date: 2025-02-21 15:42:14
// tag: 

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<int>> g(n + 1);
  std::vector<int> a(n + 1), b(n + 1), c(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i] >> b[i];
  }
  std::vector<int> is1(n + 1);
  for (int i = 1; i <= m; i++) {
    int x, y;
    std::cin >> x >> y;
    if (x == 1) is1[y] = 1;
    if (y == 1) is1[x] = 1;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  std::vector<int> dis(n + 1, -1), f(n * 2 + 1), ans(n + 1);
  std::queue<int> q;
  q.push(1);
  dis[1] = 0;
  while (!q.empty()) {
    int u = q.front(); q.pop();
    for (int v : g[u]) {
      if (dis[v] == -1) {
        dis[v] = dis[u] + 1;
        q.push(v);
      }
    }
  }
  int mx1 = LLONG_MIN / 3, mx2 = 0, mx11 = 0;
  for (int i = 1; i <= n; i++) {
    c[i] = a[i] - dis[i] * b[i];
    if (c[i] - b[i] > mx1) {
      mx2 = mx1;
      mx11 = i;
      mx1 = c[i] - b[i];
    } else if (c[i] - b[i] > mx2) {
      mx2 = c[i] - b[i];
    }
  }
  for (int i = 1; i <= n; i++) {
    if (is1[i]) {
      if (i == mx11) f[i] = ans[i] = mx2;
      else f[i] = ans[i] = mx1;
    }
  }
  // for (int i = 1; i <= n; i++) {
  //   std::cerr << dis[i] << " \n"[i == n];
  // }
  std::vector<std::vector<int>> g2(n * 2 + 1);
  // std::cerr << "qwq\n";
  std::vector<int> vis(n * 2 + 1);
  auto dfs = [&](auto self, int u, int p) -> void {
    if (vis[u]) return;
    vis[u] = 1;
    // std::cerr << u << ": ";
    // for (int v : g[u]) std::cerr << v << " ";
    // std::cerr << '\n';
    for (int v : g[u]) {
      if (v != p) {
        // std::cerr << "qwq" << u << ' ' << v << '\n';
        if (dis[v] == dis[u] + 1) {
          g2[u].push_back(v);
          g2[u + n].push_back(v + n);
        } else if (dis[v] == dis[u]) {
          g2[u].push_back(v + n);
          g2[v].push_back(u + n);
        } else if (dis[v] == dis[u] - 1) {
          g2[v].push_back(u);
          g2[v + n].push_back(u + n);
        }
        self(self, v, u);
      }
    }
  };
  dfs(dfs, 1, 0);
  std::fill(vis.begin(), vis.end(), 0);
  auto dfs2 = [&](auto self, int u, int p) -> void {
    if (vis[u]) return;
    vis[u] = 1;
    if (u <= n) f[u] = std::max(f[u], a[u] - (dis[u] - 1) * b[u]);
    else f[u] = std::max(f[u], a[u - n] - dis[u - n] * b[u - n]);
    // std::cerr << u << ": ";
    // for (int v : g2[u]) std::cerr << v << " ";
    // std::cerr << '\n';
    for (int v : g2[u]) {
      if (v != p) {
        self(self, v, u);
        ans[u > n ? u - n : u] = std::max(ans[u > n ? u - n : u], f[v]);
        f[u] = std::max(f[u], f[v]);
      }
    }
  };
  dfs2(dfs2, 1, 0);
  for (int i = 1; i <= n; i++) {
    if (is1[i]) {
      std::cout << ans[i] << '\n';
    }
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