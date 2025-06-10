// date: 2025-05-25 18:08:50
// tag: 倍增好题。怎么他妈的什么玩意都可以倍增啊？顺便倍增不一定是点域，也可以是值域上的，反正就是各种域。

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  std::vector<std::vector<int>> g(n + 1);
  for (int i = 2; i <= n; i++) {
    int x;
    std::cin >> x;
    g[x].push_back(i);
  }
  int q;
  std::cin >> q;
  std::vector<std::vector<int>> f(21, std::vector<int>(n + 1));
  std::vector<int> dep(n + 1);
  std::vector<int> pos(n + 2);
  auto dfs = [&](auto self, int u, int p) -> void {
    dep[u] = dep[p] + 1;
    int old = pos[a[u]];
    pos[a[u]] = u;
    if (pos[a[u] + 1]) {
      f[0][u] = pos[a[u] + 1];
    }
    for (int i = 1; i <= 20; i++) {
      f[i][u] = f[i - 1][f[i - 1][u]];
    }
    for (int v : g[u]) {
      if (v != p) {
        self(self, v, u);
      }
    }
    pos[a[u]] = old;
  };
  dfs(dfs, 1, 0);
  // for (int i = 1; i <= n; i++) {
  //   std::cerr << f[0][i] << ' ';
  // }
  // std::cerr << '\n';
  while (q--) {
    int s, t;
    std::cin >> s >> t;
    int ans = 0;
    for (int i = 20; i >= 0; i--) {
      if (dep[s] - dep[t] >= (1ll << i) && f[i][s]) {
        ans += 1ll << i;
        s = f[i][s];
      }
    }
    std::cout << ans + 1 << '\n';
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