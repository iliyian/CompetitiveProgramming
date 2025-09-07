#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, k;
  std::cin >> n >> k;
  std::vector<int> a(n + 1);
  std::vector<std::vector<std::array<int, 3>>> f(n + 1, std::vector<std::array<int, 3>>(k + 1, {LLONG_MIN / 3, LLONG_MIN / 3, LLONG_MIN / 3}));
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
  auto dfs = [&](auto self, int u, int p) -> void {
    if (g[u].size() == 1 && u != 1) {
      f[u][1][1] = f[u][1][2] = a[u];
      return;
    }
    f[u][0][0] = 0;
    bool h = false;
    for (int v : g[u]) {
      if (v != p) {
        self(self, v, u);
        auto nf = f[u];
        for (int i = 0; i <= k; i++) {
          for (int j = 0; j <= k; j++) {
            if (i + j <= k) {
              nf[i + j][0] = std::max(nf[i + j][0], f[u][i][0] + std::max({f[v][j][0], f[v][j][1], f[v][j][2]}));
              nf[i + j][1] = std::max(nf[i + j][1], f[u][i][1] + std::max({f[v][j][0], f[v][j][1], f[v][j][2]}));
              nf[i + j][2] = std::max(nf[i + j][2], f[u][i][2] + std::max({f[v][j][0], f[v][j][1], f[v][j][2]}));

              nf[i + j][1] = std::max(nf[i + j][1], f[u][i][0] + f[v][j][1] + a[u]);
            }
            if (0 <= i + j - 1 && i + j - 1 <= k) {
              nf[i + j - 1][2] = std::max(nf[i + j - 1][2], f[u][i][1] + f[v][j][1]);
            }
          }
        }
        f[u] = nf;
      }
    }
  };
  dfs(dfs, 1, 0);
  int ans = 0;
  // for (int i = 1; i <= n; i++) {
  //   for (int j = 0; j <= k; j++) {
  //     std::cerr << i << ' ' << j << ' ' << f[i][j][0] << ' ' << f[i][j][1] << ' ' << f[i][j][2] << '\n';
  //   }
  // }
  for (int i = 0; i <= k; i++) {
    ans = std::max({ans, f[1][i][0], f[1][i][1], f[1][i][2]});
  }
  std::cout << ans << '\n';
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