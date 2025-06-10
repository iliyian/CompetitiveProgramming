#include <bits/stdc++.h>
#define int long long

constexpr int N = 1e6;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  std::vector<std::vector<int>> g(n + 1);
  for (int i = 2; i <= n; i++) {
    int x, y;
    std::cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  auto dfs = [&](auto self, int u, int p) -> std::bitset<1001> {
    std::bitset<1001> f;
    f[0] = 1;
    if (g[u].size() == 1 && u != 1) {
      f[a[u]] = 1;
      return f;
    }
    for (int v : g[u]) {
      if (v != p) {
        auto g = self(self, v, u);
        auto tf = f;
        for (int i = a[v]; i >= 1; i--) {
          if (g[i]) {
            f |= tf << i;
          }
        }
      }
    }
    return f;
  };
  auto ans = dfs(dfs, 1, 0);
  for (int i = a[1]; i >= 0; i--) {
    if (ans[i]) {
      std::cout << i << '\n';
      return;
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