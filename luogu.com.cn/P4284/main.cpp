// date: 2024-12-12 23:47:35
// tag: 十分细节的换根概率dp
// 关键在于推父亲对当前节点贡献的时候，需要考虑上兄弟节点和祖节点的共同的贡献，并将之排除或计算在内

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<std::vector<std::pair<int, double>>> g(n + 1);
  for (int i = 2; i <= n; i++) {
    int x, y, p;
    std::cin >> x >> y >> p;
    g[x].push_back({y, double(p) / 100});
    g[y].push_back({x, double(p) / 100});
  }
  std::vector<double> a(n + 1);
  std::vector<double> f(n + 1), h(n + 1);
  for (int i = 1; i <= n; i++) {
    int x;
    std::cin >> x;
    a[i] = double(x) / 100;
  }
  auto dfs1 = [&](auto self, int u, int p) -> void {
    double t = 1;
    f[u] = a[u];
    for (auto [v, w] : g[u]) {
      if (v != p) {
        self(self, v, u);
        // t *= (1 - w * f[v]);
        f[u] = f[u] + w * f[v] - w * f[u] * f[v];
      }
    }
    // f[u] += (1 - a[u]) * (1 - t);
  };
  auto dfs2 = [&](auto self, int u, int p) -> void {
    for (auto [v, w] : g[u]) {
      if (v != p) {
        if (f[v] * w == 1) {
          h[v] = h[u];
        } else {
          double gu = (h[u] - f[v] * w) / (1 - f[v] * w);
          // u被其他节点激活的概率，f[u]=(f[v]w|gu)，包括u的pa
          h[v] = gu * w + f[v] - gu * w * f[v];
        }
        self(self, v, u);
      }
    }
  };
  dfs1(dfs1, 1, 0);
  h[1] = f[1];
  dfs2(dfs2, 1, 0);
  double ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += h[i];
    // std::cout << f[i] << ' ' << gg[i] << ' ' << h[i] << '\n';
  }
  std::cout << std::fixed << std::setprecision(6) << ans << '\n';
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