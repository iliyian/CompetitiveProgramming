#include <bits/stdc++.h>
#define int long long

constexpr int inf = LLONG_MAX / 3;

void solve() {
  int n, m, k;
  std::cin >> n >> m >> k;
  std::vector<std::vector<int>> g(n + 1);
  std::vector<std::set<int>> g2(n + 1);
  for (int i = 1; i <= n; i++) {
    int k;
    std::cin >> k;
    for (int j = 1; j <= k; j++) {
      int v;
      std::cin >> v;
      g[i].push_back(v);
    }
  }
  for (int i = 1; i <= m; i++) {
    int x, y;
    std::cin >> x >> y;
    // g2[x].push_back(y);
    g2[x].insert(y);
  }
  std::vector<int> isK(n + 1), f(n + 1, inf);
  auto dfs = [&](auto self, int u) -> void {
    if (isK[u]) {
      f[u] = 0;
      return;
    }
    if (g[u].size() == 0) return;
    // std::cout << "cur: " << u << ' ' << g[u].size() << '\n';
    if (g[u].size() == 1) {
      self(self, g[u].front());
      f[u] = f[g[u].front()];
      return;
    }
    if (g2.empty()) {
      // std::cout << "cur: " << u << '\n';
      for (int v : g[u]) {
        self(self, v);
        if (f[v] == inf) {
          f[u] = inf;
          return;
        }
        f[u] += f[v]; // 全都可能
      }
    } else {
      int sum = 0;
      for (int v : g[u]) {
        self(self, v);
      }
      for (int v: g2[u]) {
        f[u] = std::min(f[u], f[v] + 1); // 确定
      }
      for (int v : g[u]) {
        if (f[v] == inf) {
          sum = inf;
          break;
        }
        sum += f[v];
      }
      f[u] = std::min(f[u], sum);
    }
  };
  for (int i = 1; i <= k; i++) {
    int x;
    std::cin >> x;
    isK[x] = 1;
  }
  dfs(dfs, 1);
  // std::cout << '\n';
  // for (int i = 1; i <= n; i++) {
  //   std::cout << f[i] << " \n"[i == n];
  // }
  // for (int i = 1; i <= n; i++) {
  //   std::cout << isK[i] << " \n"[i == n];
  // }
  std::cout << (f[1] == inf ? -1 : f[1]) << '\n';
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