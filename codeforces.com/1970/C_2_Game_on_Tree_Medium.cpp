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
  std::vector<int> f(n + 1);
  auto dfs = [&](auto self, int u, int p) -> void {
    for (int v : g[u]) {
      if (v != p) {
        self(self, v, u);
        if (!f[v]) {
          f[u] = 1;
        }
      }
    }
  };
  while (q--) {
    int x;
    std::cin >> x;
    dfs(dfs, x, 0);
    std::cout << (f[x] ? "Ron" : "Hermione") << '\n';
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