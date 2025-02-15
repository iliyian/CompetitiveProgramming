// date: 2025-01-22 16:17:24
// tag: 换根dp，动态规划存储的状态务必选择方便的！！

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<std::vector<int>> g(n + 1);
  std::vector<int> dis(n + 1, -1);
  for (int i = 1; i <= n - 1; i++) {
    int x, y;
    std::cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  std::queue<int> q;
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (g[i].size() == 1) {
      q.push(i);
      dis[i] = 0;
      cnt++;
    }
  }
  while (!q.empty()) {
    int u = q.front(); q.pop();
    for (int v : g[u]) {
      if (dis[v] == -1) {
        dis[v] = dis[u] + 1;
        q.push(v);
      }
    }
  }
  std::vector<int> f(n + 1);
  int ans = cnt * (n - cnt);
  auto dfs = [&](this auto &&self, int u, int p) -> void {
    for (int v : g[u]) {
      if (v != p) {
        self(v, u);
        f[u] += f[v];aa
      }
    }
    f[u] += dis[u] >= 2;
  };
  auto dfs2 = [&](this auto &&self, int u, int p) -> void {
    if (p && dis[p] <= 1 && dis[u] >= 1) {
      ans += f[1] - f[u];
      // std::cout << u << " up: " << f[1] - f[u] << '\n';
    }
    for (int v : g[u]) {
      if (v != p) {
        if (dis[v] <= 1 && dis[u] >= 1) {
          ans += f[v];
          // std::cout << u << " down: " << f[v] << '\n';
        }
        self(v, u);
      }
    }
  };
  dfs(1, 0);
  dfs2(1, 0);
  std::cout << ans << '\n';
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