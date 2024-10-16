// date: 2024-10-11 16:26:27
// tag: 树的重心，树的直径

#include <bits/stdc++.h>
#define int long long

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  freopen("E.in", "r", stdin);
  int n, k;
  std::cin >> n >> k;
  std::vector<std::vector<int>> g(n + 1);
  std::vector<std::pair<int, int>> edges(n);
  for (int i = 1; i <= n - 1; i++) {
    auto &[x, y] = edges[i];
    std::cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  int ans = INT_MAX;
  for (int i = 1; i <= n; i++) {
    std::queue<std::pair<int, int>> q;
    std::vector<int> dep(n + 1, -1);
    q.push({i, 0});
    int cnt = k, maxd = INT_MIN;
    while (!q.empty()) {
      auto [u, d] = q.front(); q.pop();
      if (dep[u] != -1) continue;
      maxd = std::max(maxd, d);
      dep[u] = d;
      if (!--cnt) {
        break;
      }
      for (int v : g[u]) {
        q.push({v, d + 1});
      }
    }
    if (maxd != INT_MIN) {
      ans = std::min(ans, maxd * 2 + 1);
    }
  }
  for (int i = 1; i <= n - 1; i++) {
    auto [x, y] = edges[i];
    std::queue<std::pair<int, int>> q;
    std::vector<int> dep(n + 1, -1);
    q.push({x, 0});
    q.push({y, 0});
    int cnt = k, maxd = INT_MIN;
    while (!q.empty()) {
      auto [u, d] = q.front(); q.pop();
      if (dep[u] != -1) continue;
      maxd = std::max(maxd, d);
      dep[u] = d;
      if (!--cnt) {
        break;
      }
      for (int v : g[u]) {
        q.push({v, d + 1});
      }
    }
    if (maxd != INT_MIN) {
      ans = std::min(ans, maxd * 2 + 2);
    }
  }
  std::cout << ans << '\n';

  return 0;
}