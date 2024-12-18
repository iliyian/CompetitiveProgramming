// date: 2024-09-12 12:19:21
// tag: 倍增树上线性基

#include <bits/stdc++.h>
#define int long long

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  freopen("main.in", "r", stdin);
  int n, q;
  std::cin >> n >> q;
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
  std::vector<int> dep(n + 1);
  std::vector<std::vector<std::vector<int>>> d(16, std::vector<std::vector<int>>(n + 1, std::vector<int>(63)));
  std::vector<std::vector<int>> pa(16, std::vector<int>(n + 1));
  auto insert = [](std::vector<int> &d, int x) {
    if (!x) return;
    for (int i = 62; i >= 0; i--) {
      if (x >> i & 1) {
        if (d[i]) {
          x ^= d[i];
        } else {
          d[i] = x;
          return;
        }
      }
    }
  };
  auto merge = [&insert](std::vector<int> &a, std::vector<int> &b) {
    for (int i = 62; i >= 0; i--) {
      insert(a, b[i]);
    }
  };
  auto dfs = [&](auto self, int u, int p) -> void {
    pa[0][u] = p;
    insert(d[0][u], a[pa[0][u]]);
    dep[u] = dep[p] + 1;
    for (int i = 1; i <= 15; i++) {
      pa[i][u] = pa[i - 1][pa[i - 1][u]];
      d[i][u] = d[i - 1][u];
      merge(d[i][u], d[i - 1][pa[i - 1][u]]);
    }
    for (int v : g[u]) {
      if (v != p) {
        self(self, v, u);
      }
    }
  };

  dfs(dfs, 1, 0);
  while (q--) {
    int x, y;
    std::cin >> x >> y;
    std::vector<int> cur(63);
    insert(cur, a[x]);
    insert(cur, a[y]);
    if (dep[x] < dep[y]) std::swap(x, y);
    for (int i = 15; i >= 0; i--) {
      if (dep[x] - (1 << i) >= dep[y]) {
        merge(cur, d[i][x]);
        x = pa[i][x];
      }
    }

    if (x != y) {
      for (int i = 15; i >= 0; i--) {
        if (pa[i][x] != pa[i][y]) {
          merge(cur, d[i][x]);
          merge(cur, d[i][y]);
          x = pa[i][x];
          y = pa[i][y];
        }
      }
      insert(cur, a[pa[0][x]]);
    }

    int ans = 0;
    for (int i = 62; i >= 0; i--) {
      if ((ans ^ cur[i]) > ans) {
        ans ^= cur[i];
      }
    }

    std::cout << ans << '\n';
  }

  return 0;
}