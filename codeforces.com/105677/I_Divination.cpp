#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<std::vector<int>> g(n + 1);
  for (int i = 1; i <= n; i++) {
    int c;
    std::cin >> c;
    for (int j = 1; j <= c; j++) {
      int x;
      std::cin >> x;
      g[i].push_back(x);
    }
  }
  std::vector<int> f(n + 1, -1);
  int mx = 0;
  auto dfs = [&](auto self, int u) -> void {
    if (f[u] != -1) return;
    f[u] = 1;
    for (int v : g[u]) {
      self(self, v);
      f[u] = std::max(f[u], f[v] + 1);
    }
    mx = std::max(mx, f[u]);
  };
  for (int i = 1; i <= n; i++) {
    if (f[i] == -1) {
      dfs(dfs, i);
    }
  }
  std::cout << (mx == n) << '\n';
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