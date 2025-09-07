#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  std::vector<std::vector<int>> g(n + 1);
  for (int i = 1; i < n; i++) {
    int x, y;
    std::cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  std::vector<std::vector<int>> pa(21, std::vector<int>(n + 1));
  std::vector<int> sgcd(n + 1);
  std::vector<std::vector<int>> pregcd(n + 1), sufgcd(n + 1);
  std::vector<std::vector<int>> pagcd(21, std::vector<int>(n + 1));
  auto dfs = [&](auto self, int u, int p) -> void {
    pa[0][u] = p;
    for (int i = 1; i <= 20; i++) {
      pa[i][u] = pa[i - 1][pa[i - 1][u]];
    }
    sgcd[u] = a[u];
    pregcd[u].assign(g[u].size(), 0);
    sufgcd[u].assign(g[u].size(), 0);
    for (int i = 0; i < g[u].size(); i++) {
      int v = g[u][i];
      if (v != p) {
        self(self, v, u);
        sgcd[u] = std::gcd(sgcd[u], sgcd[v]);
        sufgcd[u][i] = pregcd[u][i] = sgcd[v];
      }
    }
    for (int i = 1; i < g[u].size(); i++) {
      pregcd[u][i] = std::gcd(pregcd[u][i], pregcd[u][i - 1]);
    }
    for (int i = g[u].size() - 2; i >= 0; i--) {
      sufgcd[u][i] = std::gcd(sufgcd[u][i + 1], sufgcd[u][i]);
    }
    for (int i = 0; i < g[u].size(); i++) {
      int v = g[u][i];
      int gg = 0;
      if (i) gg = std::gcd(gg, pregcd[u][i - 1]);
      if (i < g[u].size() - 1) gg = std::gcd(gg, sufgcd[u][i + 1]);
      pagcd[0][v] = gg;
    }
  };
  dfs(dfs, 1, 0);
  auto dfs2 = [&](auto self, int u, int p) -> void {
    for (int i = 1; i <= 20; i++) {
      pagcd[i][u] = std::gcd(pagcd[i - 1][u], pagcd[i - 1][pa[i - 1][u]]);
    }
    for (int v : g[u]) {
      if (v != p) {
        self(self, v, u);
      }
    }
  };
  dfs2(dfs2, 1, 0);
  for (int u = 1; u <= n; u++) {
    int ans = 0, v = u;
    for (int j = 20; j >= 0; j--) {
      if (pa[j][v]) {
        ans = std::gcd(ans, pagcd[j][v]);
        v = pa[j][v];
      }
    }
    std::cout << ans << ' ';
  }
  std::cout << '\n';
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