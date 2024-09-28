#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n, c;
  std::cin >> n >> c;
  std::vector<std::array<int, 2>> f(n + 1);
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  std::vector<std::vector<int>> g(n + 1);
  for (int i = 1; i <= n - 1; i++) {
    int x, y;
    std::cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  auto dfs = [&](auto self, int u, int p) -> void {
    f[u][1] = a[u];
    for (int v : g[u]) {
      if (v != p) {
        self(self, v, u);
        f[u][0] += std::max(f[v][0], f[v][1]);
        f[u][1] += std::max(f[v][1] - 2 * c, f[v][0]);
      }
    }
  };
  dfs(dfs, 1, 0);
  std::cout << std::max(f[1][0], f[1][1]) << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("F.in", "r", stdin);

  int t;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}