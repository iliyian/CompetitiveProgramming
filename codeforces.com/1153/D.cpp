// date: 2024-08-08 13:01:48
// tag: 树形神仙dp

#include <bits/stdc++.h>
#define int long long
// using namespace std;

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("D.in", "r", stdin);
  freopen("D.out", "w", stdout);

  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  std::vector<std::vector<int>> g(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  for (int i = 2; i <= n; i++) {
    int x;
    std::cin >> x;
    g[x].push_back(i);
  }
  std::vector<int> f(n + 1), siz(n + 1);
  int cnt = 0;
  auto dfs = [&](auto self, int u, int p) -> void {
    if (g[u].empty()) {
      f[u] = 1;
      cnt++;
      return;
    }
    if (a[u]) f[u] = LLONG_MAX;
    siz[u] = 0;
    for (int v : g[u]) {
      if (v != p) {
        self(self, v, u);
        siz[u] += siz[v];
        if (a[u]) {
          f[u] = std::min(f[u], f[v]);
        } else {
          f[u] += f[v];
        }
      }
    }
  };
  dfs(dfs, 1, 0);
  std::cout << cnt + 1 - f[1] << '\n';

  return 0;
}