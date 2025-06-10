// date: 2025-04-09 11:57:20
// tag: 换根dp下，对子树操作，当前节点为根节点时，当前节点的子树是整颗树而非树的一部分，这点容易忽略。因此记录单个子树的dp值无意义。
// 但是这题实际上根本不需要按位。

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
    int x, y;
    std::cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  std::vector<std::vector<std::array<int, 2>>> f(20, std::vector<std::array<int, 2>>(n + 1, {0, 0}));
  std::vector<std::vector<std::array<int, 2>>> s(20, std::vector<std::array<int, 2>>(n + 1, {0, 0}));
  std::vector<int> siz(n + 1);
  auto dfs = [&](auto self, int u, int p, int w) -> void {
    siz[u] = 1;
    for (int v : g[u]) {
      if (v != p) {
        self(self, v, u, w);
        siz[u] += siz[v];
        for (int i = 0; i < 2; i++) {
          s[w][u][i] += f[w][v][i];
        }
      }
    } 
    for (int i = 0; i < 2; i++) {
      f[w][u][i] = ((a[u] >> w & 1) == i ? s[w][u][i] : (siz[u] << w) + s[w][u][i ^ 1]);
    }
  };
  std::vector<std::vector<std::array<int, 2>>> h(20, std::vector<std::array<int, 2>>(n + 1, {0, 0}));
  auto dfs2 = [&](auto self, int u, int p, int w) -> void {
    for (int v : g[u]) {
      if (v != p) {
        for (int i = 0; i < 2; i++) {
          h[w][v][i] = ((a[u] >> w & 1) == i 
            ? h[w][u][i] + s[w][u][i] - f[w][v][i]
            : h[w][u][i ^ 1] + s[w][u][i ^ 1] - f[w][v][i ^ 1] + ((n - siz[v]) << w));
        }
        self(self, v, u, w);
      }
    }
  };
  for (int i = 0; i <= 19; i++) {
    dfs(dfs, 1, 0, i);
  }
  for (int i = 0; i <= 19; i++) {
    dfs2(dfs2, 1, 0, i);
  }
  // 7476523 4727035 4727035 10254043 4727035 9445607 5379819 11093419 5508043 7475471
  for (int i = 1; i <= n; i++) {
    int ans = 0;
    for (int j = 19; j >= 0; j--) {
      ans += std::min(
        s[j][i][a[i] >> j & 1] + h[j][i][a[i] >> j & 1],
        s[j][i][a[i] >> j & 1 ^ 1] + h[j][i][a[i] >> j & 1 ^ 1] + ((n - 1) << j)
      );
      // if (i == 3) {
      //   std::cerr << f[j][i][0] << ' ' << h[j][i][0] << ' ' << f[j][i][1] << ' ' << h[j][i][1] << ' ' << j << ' ' << ans << '\n';
      // }
    }
    std::cout << ans << " \n"[i == n];
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