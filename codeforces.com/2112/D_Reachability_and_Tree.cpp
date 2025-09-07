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
  int x = -1;
  auto dfs = [&](auto self, int u, int p) -> void {
    if (g[u].size() == 2) {
      x = u;
    }
    for (int v : g[u]) {
      if (v != p) {
        self(self, v, u);
      }
    }
  };
  dfs(dfs, 1, 0);
  if (x == -1) {
    std::cout << "NO\n";
    return;
  }
  std::cout << "YES\n";
  auto dfs2 = [&](auto self, int u, int p, bool f) -> void {
    if (p) {
      if (f) {
        std::cout << u << ' ' << p << '\n';
      } else {
        std::cout << p << ' ' << u << '\n';
      }
    }
    for (int v : g[u]) {
      if (v != p) {
        self(self, v, u, f ^ 1);
      }
    }
  };
  dfs2(dfs2, g[x].front(), x, 1);
  dfs2(dfs2, g[x].back(), x, 0);
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