// date: 2025-05-13 19:17:53
// tag: 什么水题？

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  std::vector<int> pa(n + 1), siz(n + 1, 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    pa[i] = i;
  }
  auto find = [&](auto self, int x) -> int {
    return x == pa[x] ? x : pa[x] = self(self, pa[x]);
  };
  auto merge = [&](int x, int y) -> bool {
    x = find(find, x), y = find(find, y);
    if (x == y) return false;
    if (siz[x] > siz[y]) std::swap(x, y);
    pa[x] = y;
    siz[y] += siz[x];
    return true;
  };
  std::vector<std::pair<int, int>> e;
  for (int i = 1; i <= n - 1; i++) {
    int x, y;
    std::cin >> x >> y;
    e.push_back({x, y});
    if (a[x] <= a[y] * 2 && a[y] <= a[x] * 2) {
      merge(x, y);
    }
  }
  std::vector<int> in(n + 1);
  std::vector<std::vector<int>> g(n + 1);
  for (auto [x, y] : e) {
    int xx = find(find, x), yy = find(find, y);
    if (xx != yy) {
      if (a[x] <= a[y] * 2) {
        g[xx].push_back(yy);
        in[yy]++;
      } else {
        g[yy].push_back(xx);
        in[xx]++;
      }
    }
  }
  bool f = false;
  int ans = 0;
  std::vector<int> vis(n + 1);
  for (int i = 1; i <= n; i++) {
    if (pa[i] == i) {
      if (!in[i]) {
        ans = siz[pa[i]];
        vis[i] = 1;
        int sum = 0;
        auto dfs = [&](auto self, int u) -> void {
          for (int v : g[u]) {
            if (!vis[v]) {
              vis[v] = 1;
              sum += siz[v];
              self(self, v);
            }
          }
        };
        sum += siz[i];
        dfs(dfs, i);
        if (sum != n) {
          std::cout << 0 << '\n';
          return;
        }
        std::cout << siz[i] << '\n';
        return;
      }
    }
  }
  assert(false);
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