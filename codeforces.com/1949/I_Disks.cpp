// date: 2025-05-03 23:11:29
// tag: 这种图不是联通的情况，不能判定当前联通块无解就直接退出，还需要把联通块所有内容都打上标记的。不然会重复访问！！！

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<std::array<int, 3>> a(n + 1);
  for (int i = 1; i <= n; i++) {
    auto &[x, y, r] = a[i];
    std::cin >> x >> y >> r;
  }
  std::vector<std::vector<int>> g(n + 1);
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      auto [x, y, r] = a[i];
      auto [_x, _y, _r] = a[j];
      if ((x - _x) * (x - _x) + (y - _y) * (y - _y) == (r + _r) * (r + _r)) {
        g[i].push_back(j);
        g[j].push_back(i);
      }
    }
  }
  std::vector<int> vis(n + 1);
  bool f = true;
  int c[2] {};
  auto dfs = [&](auto self, int u, int p, int typ) -> void {
    vis[u] = typ;
    c[typ - 1]++;
    for (int v : g[u]) {
      if (!vis[v]) {
        self(self, v, u, 3 - typ);
      } else if (vis[v] == typ) {
        f = false;
      }
    }
  };
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      f = true;
      c[0] = c[1] = 0;
      dfs(dfs, i, 1, 1);
      if (f && c[1] != c[0]) {
        std::cout << "YES\n";
        return;
      }
    }
  }
  std::cout << "NO\n";
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