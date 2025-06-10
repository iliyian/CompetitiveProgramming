#include <bits/stdc++.h>
#define int long long

void solve() {
  int n1;
  std::cin >> n1;
  std::vector<std::vector<int>> g1(n1 + 1);
  for (int i = 2; i <= n1; i++) {
    int x, y;
    std::cin >> x >> y;
    g1[x].push_back(y);
    g1[y].push_back(x);
  }
  int n2;
  std::cin >> n2;
  std::vector<std::vector<int>> g2(n2 + 1);
  for (int i = 2; i <= n2; i++) {
    int x, y;
    std::cin >> x >> y;
    g2[x].push_back(y);
    g2[y].push_back(x);
  }
  int maxd = 0, c = 0;
  std::vector<int> d1(n1 + 1), d2(n2 + 1), mxd1(n1 + 1), mxd2(n2 + 1);
  auto dfs = [&](auto self, int u, int p, std::vector<std::vector<int>> &g, std::vector<int> &d, std::vector<int> &mxd) -> void {
    mxd[u] = std::max(mxd[u], d[u]);
    for (int v : g[u]) {
      if (v != p) {
        d[v] = d[u] + 1;
        if (d[v] > maxd) {
          maxd = d[v];
          c = v;
        }
        self(self, v, u, g, d, mxd);
      }
    }
  };
  dfs(dfs, 1, 0, g1, d1, mxd1);
  // std::cerr << c << '\n';
  d1[c] = 0, maxd = 0;
  dfs(dfs, c, 0, g1, d1, mxd1);
  int dia1 = maxd;
  // std::cerr << c << '\n';
  d1[c] = 0;
  dfs(dfs, c, 0, g1, d1, mxd1);
  
  maxd = 0, c = 0;
  dfs(dfs, 1, 0, g2, d2, mxd2);
  // std::cerr << c << ' ';
  d2[c] = 0, maxd = 0;
  dfs(dfs, c, 0, g2, d2, mxd2);
  int dia2 = maxd;
  // std::cerr << c << '\n';
  d2[c] = 0;
  dfs(dfs, c, 0, g2, d2, mxd2);

  std::sort(mxd2.begin() + 1, mxd2.end());
  std::vector<int> s2(n2 + 2);
  // for (int i = 1; i <= n1; i++) {
  //   // std::cerr << d1[i] << ' ';
  //   std::cerr << mxd1[i] << " \n"[i == n1];
  // }
  // for (int i = 1; i <= n2; i++) {
  //   // std::cerr << d2[i] << ' ';
  //   std::cerr << mxd2[i] << " \n"[i == n2];
  // }
  for (int i = n2; i >= 1; i--) {
    s2[i] = s2[i + 1] + mxd2[i];
  }
  int maxdia = std::max(dia1, dia2), ans = 0;
  for (int i = 1; i <= n1; i++) {
    auto p = std::lower_bound(mxd2.begin() + 1, mxd2.end(), maxdia - mxd1[i] - 1) - mxd2.begin();
    int cnt = n2 - p + 1;
    // std::cerr << mxd1[i] << ' ' << p << ' ' << mxd2[p] << '\n';
    ans += cnt * (mxd1[i] + 1) + s2[p];
    ans += (n2 - cnt) * maxdia;
  }
  std::cout << ans << '\n';
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