// date: 2025-08-31 16:45:27
// tag: 特殊距离定义的最短路，图论（所以最短路是不是就三种，要么特殊距离，要么分层图，要么拆点拆边）

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m, k;
  std::cin >> n >> m >> k;
  std::vector<std::vector<std::array<int, 3>>> g(n + 1);
  for (int i = 1; i <= m; i++) {
    int x, y, c, w;
    std::cin >> x >> y >> c >> w;
    g[x].push_back({y, c, w});
    g[y].push_back({x, c, w});
  }
  std::vector<int> a(k + 1), b(k + 1);
  std::vector<std::vector<int>> ra(m + 1);
  for (int i = 1; i <= k; i++) {
    std::cin >> a[i] >> b[i];
    ra[a[i]].push_back(i);
  }
  std::vector<std::vector<std::vector<int>>> mx(m + 1);
  auto query = [&](int i, int l, int r) {
    int len = std::__lg(r - l + 1);
    return std::max(mx[i][len][l], mx[i][len][r - (1 << len) + 1]);
  };
  for (int i = 1; i <= m; i++) {
    if (ra[i].empty()) continue;
    int len = std::__lg(ra[i].size()), n = ra[i].size();
    mx[i].assign(len + 1, std::vector<int>(n));
    for (int j = 0; j < n; j++) {
      mx[i][0][j] = b[ra[i][j]];
    }
    for (int j = 1; j <= len; j++) {
      for (int k = 0; k + (1 << (j - 1)) < n; k++) {
        mx[i][j][k] = std::max(mx[i][j - 1][k], mx[i][j - 1][k + (1 << (j - 1))]);
      }
    }
  }
  std::priority_queue<std::array<int, 3>, std::vector<std::array<int, 3>>, std::greater<>> q;
  std::vector<std::array<int, 2>> dis(n + 1, {LLONG_MAX / 3, LLONG_MAX / 3});
  dis[1] = {0, 0};
  q.push({0, 0, 1});
  while (!q.empty()) {
    auto [p, d, u] = q.top(); q.pop();
    if (dis[u] != std::array{p, d}) continue;
    for (auto [v, c, w] : g[u]) {
      int pp = p, dd = d;
      if (c == a[p] && dd + w <= b[p]) { // 怎么tmd a[p]写成p都能过样例啊
        dd += w;
      } else {
        int L = std::ranges::upper_bound(ra[c], p) - ra[c].begin();
        int l = L, r = ra[c].size() - 1;
        pp = LLONG_MAX, dd = w;
        while (l <= r) {
          int mid = (l + r) / 2;
          if (query(c, L, mid) >= w) r = mid - 1, pp = ra[c][mid];
          else l = mid + 1;
        }
      }
      if (dis[v] > std::array{pp, dd}) {
        dis[v] = {pp, dd};
        q.push({pp, dd, v});
      }
    }
  }
  // for (int i = 1; i <= n; i++) {
  //   std::cerr << dis[i][0] << ' ' << dis[i][1] << '\n';
  // }
  for (int i = 1; i <= n; i++) {
    std::cout << (dis[i][0] != LLONG_MAX / 3);
  }
  std::cout << '\n';
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