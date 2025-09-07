#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<std::pair<int, int>>> g(n + 1);
  std::vector<std::vector<int>> col(n + 1), dis(n + 1);
  for (int i = 1; i <= m; i++) {
    int x, y, c;
    std::cin >> x >> y >> c;
    if (x == y) continue;
    col[x].push_back(c);
    col[y].push_back(c);
    g[x].push_back({y, c});
    g[y].push_back({x, c});
  }
  if (n == 1) {
    std::cout << 0 << '\n';
    return;
  }
  for (int i = 1; i <= n; i++) {
    std::sort(col[i].begin(), col[i].end());
    col[i].erase(std::unique(col[i].begin(), col[i].end()), col[i].end());
    // for (auto j : col[i]) {
    //   std::cerr << j << ' ';
    // }
    // std::cerr << '\n';
    dis[i].assign(col[i].size(), LLONG_MAX / 3);
  }
  auto get = [&](int x, int c) {
    return std::lower_bound(col[x].begin(), col[x].end(), c) - col[x].begin();
  };
  // std::queue<std::array<int, 3>> q;
  std::priority_queue<std::array<int, 3>, std::vector<std::array<int, 3>>, std::greater<>> q;
  for (auto [v, c] : g[1]) {
    int idx = get(v, c);
    dis[v][idx] = 1;
    q.push({dis[v][idx], v, idx});
  }
  while (!q.empty()) {
    auto [d, u, idx] = q.top(); q.pop();
    for (auto [v, c] : g[u]) {
      if (v == 1) continue;
      int jdx = get(v, c);
      if (dis[v][jdx] > d + (c == col[u][idx] ? 0 : 1)) {
        dis[v][jdx] = d + (c == col[u][idx] ? 0 : 1);
        q.push({dis[v][jdx], v, jdx});
      }
    }
  }
  // for (int i = 1; i <= n; i++) {
  //   for (int j : dis[i]) {
  //     std::cerr << j << ' ';
  //   }
  //   std::cerr << '\n';
  // }
  int ans = LLONG_MAX / 3;
  for (int i : dis[n]) {
    ans = std::min(ans, i);
  }
  std::cout << ans << '\n';
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