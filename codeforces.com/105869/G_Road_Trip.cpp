// date: 2025-05-30 22:59:17
// tag: 感觉倍增的题，有了思路，都很难在实现上错误。又是经典的树上倍增。

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, q, c;
  std::cin >> n >> q >> c;
  std::vector<std::vector<std::pair<int, int>>> g(n + 1);
  for (int i = 2; i <= n; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    g[x].push_back({y, w});
    g[y].push_back({x, w});
  }
  std::vector<std::vector<int>> f(21, std::vector<int>(n + 1));
  std::vector<std::vector<int>> pa(21, std::vector<int>(n + 1));
  std::vector<int> s(n + 1), dep(n + 1);
  std::vector<int> cur;
  auto dfs = [&](auto self, int u, int p) -> void {
    dep[u] = dep[p] + 1;
    pa[0][u] = p;
    int l = 0, r = cur.size() - 1, ans = 0;
    while (l <= r) {
      int mid = (l + r) / 2;
      if (s[u] - s[cur[mid]] <= c)
        r = mid - 1, ans = cur[mid];
      else
        l = mid + 1;
    }
    // std::cerr << u << ' ' << ans << '\n';
    f[0][u] = ans;
    for (int i = 1; i <= 20; i++) {
      pa[i][u] = pa[i - 1][pa[i - 1][u]];
      f[i][u] = f[i - 1][f[i - 1][u]];
    }
    cur.push_back(u);
    for (auto [v, w] : g[u]) {
      if (v != p) {
        s[v] = s[u] + w;
        self(self, v, u);
      }
    }
    cur.pop_back();
  };
  dfs(dfs, 1, 0);
  auto lca = [&](int x, int y) {
    if (dep[x] < dep[y])
      std::swap(x, y);
    for (int i = 20; i >= 0; i--) {
      if ((dep[x] - dep[y]) >> i & 1) {
        x = pa[i][x];
      }
    }
    if (x == y)
      return x;
    for (int i = 20; i >= 0; i--) {
      if (pa[i][x] != pa[i][y]) {
        x = pa[i][x], y = pa[i][y];
      }
    }
    return pa[0][x];
  };
  // for (int i = 1; i <= n; i++) {
  //   std::cerr << f[0][i] << " \n"[i == n];
  // }
  while (q--) {
    int x, y;
    std::cin >> x >> y;
    int ans = 0;
    int z = lca(x, y);
    for (int i = 20; i >= 0; i--) {
      if (dep[f[i][x]] > dep[z]) {
        x = f[i][x];
        ans += 1 << i;
      }
    }
    for (int i = 20; i >= 0; i--) {
      if (dep[f[i][y]] > dep[z]) {
        y = f[i][y];
        ans += 1 << i;
      }
    }
    int cnt = s[x] - s[z] + s[y] - s[z];
    // std::cerr << x << ' ' << y << ' ' << z << ' ' << cnt << '\n';
    ans += (cnt + c - 1) / c;
    std::cout << ans - 1 << '\n';
  }
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