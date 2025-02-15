#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<std::vector<int>> g(n + 1);
  for (int i = 1; i <= n - 1; i++) {
    int x, y;
    std::cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  std::vector<std::vector<int>> pa(20, std::vector<int>(n + 1)), f(20, std::vector<int>(n + 1));
  std::vector<int> dep(n + 1), maxdep(n + 1);
  auto dfs = [&](auto self, int u, int p) -> void {
    int d1 = 0, d2 = 0;
    dep[u] = dep[p] + 1;
    for (int v : g[u]) {
      if (v != p) {
        self(self, v, u);
        maxdep[u] = std::max(maxdep[u], maxdep[v]);
        if (maxdep[v] - dep[v] > d1) {
          d2 = d1;
          d1 = maxdep[v] - dep[v];
        } else if (maxdep[v] - dep[v] > d2) {
          d2 = maxdep[v] - dep[v];
        }
      }
    }
    for (int v : g[u]) {
      if (v != p) {
        f[0][v] = (maxdep[v] == d1 ? d2 : d1);
      }
    }
    
  };
  dfs(dfs, 1, 0);
  int q;
  std::cin >> q;
  while (q--) {
    int v, k;
    std::cin >> v >> k;
    int prv = 0;
    for (int i = 19; i >= 0; i--) {
      if (k >> i & 1) {

        prv += 1 << i;
      }
    }
  }
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