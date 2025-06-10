// date: 2025-04-21 20:42:00
// tag: 好吧，只能说一些时候变种的经典最短路算法往往是有用的，比如天梯赛的变种floyd和这个变种dijkstra，虽然有点难证，但嘿，人家就考你会不会修改经典算法。

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m;
  std::cin >> n >> m;
  int t0, t1, t2;
  std::cin >> t0 >> t1 >> t2;
  std::vector<std::vector<std::array<int, 3>>> g(n + 1);
  for (int i = 1; i <= m; i++) {
    int x, y, l1, l2;
    std::cin >> x >> y >> l1 >> l2;
    g[x].push_back({y, l1, l2});
    g[y].push_back({x, l1, l2});
  }
  auto check = [&](int mid) -> bool {
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> q;
    std::vector<int> dis(n + 1, LLONG_MAX / 3);
    q.push({dis[1] = mid, 1});
    while (!q.empty()) {
      auto [d, u] = q.top(); q.pop();
      if (dis[u] != d) continue;
      for (auto [v, l1, l2] : g[u]) {
        if (d + l1 <= t1 || d >= t2) {
          if (dis[v] > d + l1) {
            q.push({dis[v] = d + l1, v});
          }
        }
        if (d < t2) {
          if (dis[v] > t2 + l1) {
            q.push({dis[v] = t2 + l1, v});
          }
        }
        if (dis[v] > d + l2) {
          q.push({dis[v] = d + l2, v});
        }
      }
    }
    // std::cerr << mid << '\n';
    // for (int i = 1; i <= n; i++) {
      // std::cerr << i << ' ' << dis[i] << ' ';
    // }
    // std::cerr << '\n';
    return dis[n] <= t0;
  };
  int l = 0, r = t0 - 1, ans = -1;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (check(mid)) l = mid + 1, ans = mid;
    else r = mid - 1;
  }
  std::cout << (ans == LLONG_MAX / 3 ? -1 : ans) << '\n';
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