#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, s, t;
  std::cin >> n >> s >> t;
  std::vector<std::vector<int>> g(n + 1);
  for (int i = 1; i <= n - 1; i++) {
    int x, y;
    std::cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  std::vector<int> dep(n + 1), p(n + 1);
  std::iota(p.begin() + 1, p.end(), 1);
  auto dfs = [&](auto self, int u, int p) -> void {
    dep[u] = dep[p] + 1;
    for (int v : g[u]) {
      if (v != p) {
        self(self, v, u);
      }
    }
  };
  dfs(dfs, t, 0);
  std::sort(p.begin() + 1, p.end(), [&](const int &x, const int &y) {
    return dep[x] > dep[y];
  });
  for (int i = 1; i <= n; i++) {
    std::cout << p[i] << ' ';
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