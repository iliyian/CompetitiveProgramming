// date: 2024-08-18 15:47:41
// tag: 树形dp

#include <bits/stdc++.h>
#define int long long
// using namespace std;

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("F.in", "r", stdin);
  freopen("F.out", "w", stdout);

  int n;;
  std::cin >> n;
  std::vector<int> a(n + 1);
  std::vector<std::vector<int>> g(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  for (int i = 2; i <= n; i++) {
    int x, y;
    std::cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  std::vector<int> f(n + 1), s(n + 1);
  auto dfs = [&](auto self, int u, int p) -> void {
    s[u] = a[u];
    for (int v : g[u]) {
      if (v != p) {
        self(self, v, u);
        s[u] += s[v];
        f[u] += f[v] + s[v];
      }
    }
  };
  dfs(dfs, 1, 0);

  std::vector<int> h(n + 1);
  int ans = 0;
  auto dfs2 = [&](auto self, int u, int p) -> void {
    h[u] += f[u];
    ans = std::max(ans, h[u]);
    for (int v : g[u]) {
      if (v != p) {
        h[v] = h[u] - (f[v] + s[v]) + s[1] - s[v];
        self(self, v, u);
      }
    }
  };
  dfs2(dfs2, 1, 0);
  std::cout << ans << '\n';

  return 0;
}