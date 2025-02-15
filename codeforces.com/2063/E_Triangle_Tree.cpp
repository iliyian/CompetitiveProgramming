#include <bits/stdc++.h>
#define int long long

// date: 2024-11-18 19:22:45
// tag: 点分治，树的重心

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<std::vector<int>> g(n + 1);
  for (int i = 2; i <= n; i++) {
    int x, y;
    std::cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }

  std::vector<int> vis(n + 1), siz(n + 1), dis;
  int rt = 0;
  auto getdis = [&](this auto &&self, int u, int p, int d) -> void {
    dis.push_back(d);
    for (int v : g[u]) {
      if (v != p && !vis[v]) {
        self(v, u, d + 1);
      }
    }
  };

  int sum = n;
  std::vector<int> maxx(n + 1);
  auto getrt = [&](this auto &&self, int u, int p) -> void {
    siz[u] = 1;
    maxx[u] = 0;
    for (auto v : g[u]) {
      if (v != p && !vis[v]) {
        self(v, u);
        siz[u] += siz[v];
        maxx[u] = std::max(maxx[u], siz[v]);
      }
    }
    maxx[u] = std::max(maxx[u], sum - siz[u]);
    if (maxx[u] < maxx[rt]) {
      rt = u;
    }
  };

  std::vector<int> vec;
  std::vector<int> dv(n + 1), dc(n + 1);
  auto add = [&](std::vector<int> &v, int x, int c) {
    for (int i = x; i <= n; i += i & -i) v[i] += c;
  };
  auto query = [&](std::vector<int> &v, int x) {
    int ans = 0;
    for (int i = x; i > 0; i -= i & -i) ans += v[i];
    return ans;
  };
  int ans = 0;
  auto dfs = [&](this auto &&self, int u, int p) -> void {
    vis[u] = true;
    for (auto v : g[u]) {
      if (v != p && !vis[v]) {
        getdis(v, u, 1);
        // std::cerr << v << ' ' << query(dc, 1) << '\n';
        for (int d : dis) {
          ans += std::max<int>(0, (d * 2 - 1) * (vec.size() -  query(dc, d)));
          ans += std::max(0ll, query(dv, d) * 2 - 1);
        }
        while (!dis.empty()) {
          vec.push_back(dis.back());
          add(dv, dis.back(), dis.back());
          add(dc, dis.back(), 1);
          dis.pop_back();
        }
      }
    }
    // for (auto d : vec) {
    //   std::cerr << d << ' ';
    // }
    // std::cerr << '\n';
    while (!vec.empty()) {
      add(dv, vec.back(), -vec.back());
      add(dc, vec.back(), -1);
      vec.pop_back();
    }
    for (auto v : g[u]) {
      if (v != p && !vis[v]) {
        rt = 0;
        sum = siz[v];
        getrt(v, u);
        getrt(rt, 0);
        self(rt, 0);
      }
    }
  };

  rt = 0;
  maxx[0] = INT_MAX;
  getrt(1, 0);
  getrt(rt, 0);
  dfs(rt, 0);
  std::cout << ans << '\n';
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}