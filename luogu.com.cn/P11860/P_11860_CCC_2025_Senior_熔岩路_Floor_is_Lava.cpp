// date: 2025-07-21 09:47:00
// tag: 比较少见的边转换为点？然后根据性质把每个点可能最多的m^2个边缩减为m-1条？有效减少边数

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::array<int, 4>> e(m);
  std::vector<std::vector<int>> g(n + 1);
  for (int i = 0; i < m; i++) {
    auto &[w, x, y, id] = e[i];
    std::cin >> x >> y >> w;
    id = i;
    g[x].push_back(i);
    g[y].push_back(i);
  }
  std::vector<int> pos(m);
  std::sort(e.begin(), e.end());
  for (int i = 0; i < m; i++) {
    int id = e[i][3];
    pos[id] = i;
  }
  std::vector<std::vector<int>> h(m);
  for (int i = 0; i < n; i++) {
    std::ranges::sort(g[i], [&](auto x, auto y) {
      return pos[x] < pos[y];
    });
    for (int j = 1; j < g[i].size(); j++) {
      h[g[i][j - 1]].push_back(g[i][j]);
      h[g[i][j]].push_back(g[i][j - 1]);
    }
  }
  std::ranges::sort(e, [&](auto x, auto y) {
    return x[3] < y[3];
  });
  std::vector<int> dis(m, LLONG_MAX / 3);
  std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> q;
  q.push({dis[g[1][0]] = e[g[1][0]][0], g[1][0]});
  while (!q.empty()) {
    auto [d, u] = q.top(); q.pop();
    if (dis[u] != d) continue;
    for (int v : h[u]) {
      if (dis[v] > dis[u] + std::abs(e[u][0] - e[v][0])) {
        dis[v] = dis[u] + std::abs(e[u][0] - e[v][0]);
        q.push({dis[v], v});
      }
    }
  }
  int ans = LLONG_MAX / 3;
  for (int i : g[n]) {
    ans = std::min(ans, dis[i]);
  }
  std::cout << (ans == LLONG_MAX / 3 ? -1 : ans) << '\n';
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