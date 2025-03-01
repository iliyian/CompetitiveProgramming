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
  std::vector<std::array<int, 3>> f(n + 1, {LLONG_MAX / 3});
  auto dfs = [&](auto self, int u, int p) -> void {
    int sum = 0, mn = LLONG_MAX / 3;
    for (int v : g[u]) {
      if (v != p) {
        self(self, v, u);
        sum += f[v][2];
        mn = std::min(mn, f[v][1] - f[v][2]);
      }
    }
    f[u][1] = sum + 1;
    if (p == 0) {
      f[u][1] += 1;
    }
    if (mn == LLONG_MAX / 3) {
      f[u][2] = 2;
    } else {
      f[u][2] = sum + mn;
    }
  };
  dfs(dfs, 1, 0);
  // for (int i = 1; i <= n; i++) {
  //   std::cerr << f[i][1] << ' ' << f[i][2] << '\n';
  // }
  std::cout << std::min(f[1][1], f[1][2]) << '\n';
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