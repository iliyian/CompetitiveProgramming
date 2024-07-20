// date: 2024-07-17 10:29:58
// tag: 暴力，树形dp

#include <bits/stdc++.h>
#define int long long
// using namespace std;

void solve() {
  int n;
  std::cin >> n;

  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  std::vector<std::vector<int>> g(n + 1);
  for (int i = 0; i < n - 1; i++) {
    int x, y;
    std::cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  int t = 50;
  std::vector<std::vector<int>> f(n + 1, std::vector<int>(t + 1));
  auto dfs = [&](auto self, int u, int p) -> void {
    for (int i = 1; i <= t; i++) {
      f[u][i] = a[u] * i;
    }
    for (int v : g[u]) {
      if (v != p) {
        self(self, v, u);
        for (int i = 1; i <= t; i++) {
          int mn = LLONG_MAX;
          for (int j = 1; j <= t; j++) {
            if (j != i) {
              mn = std::min(mn, f[v][j]);
            }
          }
          f[u][i] += mn;
        }
        // f[u][1] += std::min(f[v][2], f[v][3]);
        // f[u][2] += std::min(f[v][1], f[v][3]);
        // f[u][3] += std::min(f[v][1], f[v][2]);
      }
    }
  };
  dfs(dfs, 1, 0);
  std::cout << *std::min_element(f[1].begin() + 1, f[1].end()) << '\n';
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("D.in", "r", stdin);
  freopen("D.out", "w", stdout);

  int _;
  std::cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}