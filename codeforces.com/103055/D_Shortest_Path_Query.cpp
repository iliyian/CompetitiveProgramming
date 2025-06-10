// date: 2025-04-16 12:35:28
// tag: 基于复杂度分析的最短路，lca

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m; 
  std::cin >> n >> m;
  std::vector<std::vector<std::pair<int, int>>> g(n + 1);
  for (int i = 1; i <= m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    g[x].push_back({y, w});
    g[y].push_back({x, w});
  }
  std::vector<std::vector<int>> dis(20, std::vector<int>(n + 1, LLONG_MAX / 3));
  for (int i = 1; i <= n; i++) {
    std::priority_queue<std::array<int, 3>, std::vector<std::array<int, 3>>, std::greater<>> q;
    q.push({dis[0][i] = 0, 0, i});
    while (!q.empty()) {
      auto [d, idx, u] = q.top(); q.pop();
      if (dis[idx][u] != d) continue;
      for (auto [v, w] : g[u]) {
        bool f = false;
        int cnt = 0, tv = v;
        while (tv) {
          tv >>= 1;
          cnt++;
          if (tv == i) {
            f = true;
            break;
          }
        }
        if (f) {
          if (dis[cnt][v] > dis[idx][u] + w) {
            q.push({dis[cnt][v] = dis[idx][u] + w, cnt, v});
          }
        }
      }
    }
  }
  int q;
  std::cin >> q;
  while (q--) {
    int x, y;
    std::cin >> x >> y;
    if (x > y) std::swap(x, y);
    int ans = LLONG_MAX / 3;
    int tx = x, ty = y, cnty = 0, cnt = 0;
    while (1) {
      int lenx = 62 - __builtin_clzll(tx), leny = 62 - __builtin_clzll(ty);
      if (lenx < leny) {
        ty >>= 1;
        cnty++;
      } else {
        break;
      }
    }
    while (tx) {
      if (tx == ty) {
        ans = std::min(ans, dis[cnt][x] + dis[cnt + cnty][y]);
      }
      tx >>= 1, ty >>= 1;
      cnt++;
    }
    std::cout << (ans == LLONG_MAX / 3 ? -1 : ans) << '\n';
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