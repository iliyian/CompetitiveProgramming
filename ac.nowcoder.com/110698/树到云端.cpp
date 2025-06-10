// date: 2025-05-24 22:02:35
// tag: 根在树上距离相关的数学式子中起到很重要的桥梁作用。这题换根。

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<std::vector<int>> g(n + 1);
  std::vector<std::array<int, 2>> e(n + 1);
  for (int i = 2; i <= n; i++) {
    int x, y;
    std::cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
    e[i] = {x, y};
  }
  std::vector<int> dep(n + 1), pa(n + 1);
  auto dfs = [&](auto self, int u, int p) -> void {
    dep[u] = dep[p] + 1;
    pa[u] = p;
    for (int v : g[u]) {
      if (v != p) {
        self(self, v, u);
      }
    }
  };
  dfs(dfs, 1, 0);
  std::vector<int> t(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> t[i];
  }
  int sum = 0;
  for (int i = 2; i <= n; i++) {
    auto [x, y] = e[i];
    if (pa[y] == x) std::swap(x, y);
    // std::cerr << x << ' ' << y << '\n';
    sum += t[x] - t[y];
  }
  std::vector<int> sans(n + 1), ans(n + 1);
  // std::cerr << sum << '\n';
  sum = (sum + 2 * t[1]) / (n - 1);
  sans[1] = sum;
  // std::cerr << sum << '\n';
  for (int i = 2; i <= n; i++) {
    // std::cerr << t[i] << ' ' << t[pa[i]] << ' ';
    sans[i] = (sum - t[i] + t[pa[i]]) / 2;
    // std::cerr << sans[i] << '\n';
  }
  auto dfs2 = [&](auto self, int u, int p) -> void {
    ans[u] = sans[u];
    for (int v : g[u]) {
      if (v != p) {
        self(self, v, u);
        ans[u] -= sans[v];
      }
    }
  };
  dfs2(dfs2, 1, 0);
  for (int i = 1; i <= n; i++) {
    std::cout << ans[i] << " \n"[i == n];
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