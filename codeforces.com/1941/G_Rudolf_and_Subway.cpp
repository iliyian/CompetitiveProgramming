// date: 2025-04-27 22:04:48
// tag: 有趣的图论拆点题，把边也视作一种特殊的点

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::array<int, 3>> edges(m + 1);
  std::vector<int> vec = {0};
  auto id = [&](int x) {
    return std::lower_bound(vec.begin() + 1, vec.end(), x) - vec.begin();
  };
  for (int i = 1; i <= m; i++) {
    auto &[x, y, w] = edges[i];
    std::cin >> x >> y >> w;
    vec.push_back(w);
  }
  int len = vec.size();
  std::sort(vec.begin() + 1, vec.end());
  std::vector<std::vector<int>> g(len + n + 1);
  for (int i = 1; i <= m; i++) {
    auto [x, y, w] = edges[i];
    w = id(w);
    g[n + w].push_back(x);
    g[n + w].push_back(y);
    g[x].push_back(n + w);
    g[y].push_back(n + w); // 点向颜色
  }
  std::priority_queue<std::array<int, 2>, std::vector<std::array<int, 2>>, std::greater<>> q;
  std::vector<int> dis(len + n + 1, LLONG_MAX / 3);
  int s, t;
  std::cin >> s >> t;
  q.push({dis[s] = 0, s});
  while (!q.empty()) {
    auto [d, u] = q.top(); q.pop();
    for (int v : g[u]) {
      if (dis[v] > dis[u] + (v > n)) {
        dis[v] = dis[u] + (v > n);
        q.push({dis[v], v});
      }
    }
  }
  std::cout << dis[t] << '\n';
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