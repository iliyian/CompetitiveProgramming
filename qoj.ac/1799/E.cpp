#include <bits/stdc++.h>
#define int long long

void solve(int _ = 1) {
  int n, m, D;
  std::cin >> n >> m >> D;
  std::vector<std::vector<int>> g(n + 1);
  for (int i = 1; i <= m; i++) {
    int x, y;
    std::cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  std::vector<std::array<int, 2>> dis(n + 1, {-1, -1});
  std::queue<std::pair<int, int>> q;
  int k;
  std::cin >> k;
  for (int i = 1; i <= k; i++) {
    int s;
    std::cin >> s;
    q.push({dis[s][0] = 0, s});
  }
  while (!q.empty()) {
    auto [d, u] = q.front(); q.pop();
    if (d >= D) continue;
    for (int v : g[u]) {
      if (dis[v][d & 1 ^ 1] == -1) {
        dis[v][d & 1 ^ 1] = d + 1;
        q.push({d + 1, v});
      }
    }
  }
  std::vector<std::array<int, 2>> dist(n + 1, {-1, -1}), prv(n + 1);
  q.push({dist[1][0] = 0, 1});
  while (!q.empty()) {
    auto [d, u] = q.front(); q.pop();
    if (u == n) {
      std::vector<int> p;
      int parity = d & 1;
      while (u) {
        p.push_back(u);
        assert(u != prv[u][parity]);
        u = prv[u][parity];
        parity ^= 1;
      }
      std::ranges::reverse(p);
      std::cout << d << '\n';
      for (auto i : p) {
        std::cout << i << ' ';
      }
      std::cout << '\n';
      return;
    }
    for (int v : g[u]) {
      if (dist[v][d & 1 ^ 1] == -1 && (d + 1 < dis[v][d & 1 ^ 1] || dis[v][d & 1 ^ 1] == -1)) {
        dist[v][d & 1 ^ 1] = d + 1;
        prv[v][d & 1 ^ 1] = u;
        q.push({d + 1, v});
      }
    }
  }
  std::cout << -1 << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int t = 1;
  std::cin >> t;
  int T = t;

  while (t--) {
    solve(T - t);
  }

  return 0;
}