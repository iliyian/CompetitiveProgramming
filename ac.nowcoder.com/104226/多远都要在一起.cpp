#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, q;
  std::cin >> n >> q;
  // assert(n != 1);
  // assert(n != 2);
  std::vector<std::vector<int>> g(n + 1);
  std::vector<int> isring(n + 1);
  for (int i = 1; i <= n; i++) {
    int x, y;
    std::cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  std::vector<int> vis(n + 1), pa(n + 1), id(n + 1);
  bool f = false;
  int tot = 0;
  auto dfs = [&](auto self, int u, int p) -> void {
    if (f) return;
    for (int v : g[u]) {
      if (v != p) {
        if (f) return;
        if (vis[v]) {
          f = true;
          isring[v] = 1;
          id[v] = ++tot;
          while (u != v) {
            isring[u] = 1;
            id[u] = ++tot;
            u = pa[u];
          }
          return;
        }
        pa[v] = u;
        vis[v] = 1;
        self(self, v, u);
      }
    }
  };
  vis[1] = 1;
  dfs(dfs, 1, 0);
  // for (int i = 1; i <= n; i++) {
  //   if (isring[i]) {
  //     std::cout << i << ' ' << id[i] << '\n';
  //   }
  // }
  std::vector<int> dep(n + 1);
  std::vector<std::vector<int>> pa2(20, std::vector<int>(n + 1));
  auto lca = [&](int x, int y) {
    if (dep[x] < dep[y]) std::swap(x, y);
    int d = dep[x] - dep[y];
    for (int i = 19; i >= 0; i--) {
      if (d >> i & 1) {
        x = pa2[i][x];
      }
    }
    if (x == y) return x;
    for (int i = 19; i >= 0; i--) {
      if (pa2[i][x] != pa2[i][y]) {
        x = pa2[i][x], y = pa2[i][y];
      }
    }
    return pa2[0][x];
  };
  auto dfs2 = [&](auto self, int u, int p, int _id) -> void {
    pa2[0][u] = p;
    for (int i = 1; i <= 19; i++) {
      pa2[i][u] = pa2[i - 1][pa2[i - 1][u]];
    }
    for (int v : g[u]) {
      if (isring[v] || v == p) continue;
      id[v] = _id;
      dep[v] = dep[u] + 1;
      self(self, v, u, _id);
    }
  };
  for (int i = 1; i <= n; i++) {
    if (isring[i]) {
      dfs2(dfs2, i, 0, id[i]);
    }
  }
  auto getdis = [&](int x, int y) {
    return dep[x] + dep[y] - 2 * dep[lca(x, y)];
  };
  while (q--) {
    int s, x, k;
    std::cin >> s >> x >> k;
    if (id[x] > id[s]) std::swap(x, s);
    if (id[x] == id[s]) {
      int d = getdis(x, s);
      // std::cerr << x << ' ' << s << ' ' << d << ' ' << tot << '\n';
      if (d <= k && (k - d) % 2 == 0) {
        std::cout << "Yes\n";
        continue;
      }
      if (dep[x] + dep[s] <= k && (k - dep[x] - dep[s]) % 2 == 0) {
        std::cout << "Yes\n";
        continue;
      }
      if (dep[x] + dep[s] + tot <= k && (k - dep[x] - dep[s] - tot) % 2 == 0) {
        std::cout << "Yes\n";
        continue;
      }
      if (dep[x] + dep[s] <= k && (k - dep[x] - dep[s]) % tot == 0) {
        std::cout << "Yes\n";
        continue;
      }
      std::cout << "No\n";
      continue;
    }

    int d1 = id[s] - id[x], t = dep[s] + dep[x];
    if (d1 + t <= k && (k - d1 - t) % 2 == 0) {
      std::cout << "Yes\n";
      continue;
    }
    if (d1 + t + tot <= k && (k - d1 - t - tot) % 2 == 0) {
      std::cout << "Yes\n";
      continue;
    }
    if (d1 + t <= k && (k - d1 - t) % tot == 0) {
      std::cout << "Yes\n";
      continue;
    }

    int d2 = id[x] - id[s] + tot;
    if (d2 + t <= k && (k - d2 - t) % 2 == 0) {
      std::cout << "Yes\n";
      continue;
    }
    if (d2 + t + tot <= k && (k - d2 - t - tot) % 2 == 0) {
      std::cout << "Yes\n";
      continue;
    }
    if (d2 + t <= k && (k - d2 - t) % tot == 0) {
      std::cout << "Yes\n";
      continue;
    }

    // std::cerr << d1 << ' ' << d2 << ' ' << t << '\n';
    std::cout << "No\n";
  }
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