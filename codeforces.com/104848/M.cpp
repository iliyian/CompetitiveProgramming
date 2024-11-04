#include <bits/stdc++.h>
#define int long long

constexpr int inf = 0x3f3f3f3f3f3f3f3f;

void solve() {
  int n, m, t;
  std::cin >> n >> m >> t;
  std::vector<std::vector<std::pair<int, double>>> g(n + 1);
  for (int i = 1; i <= m; i++) {
    int x, y, l, c;
    std::cin >> x >> y >> l >> c;
    double w = std::sqrt(l * c);
    g[x].push_back({y, w});
    g[y].push_back({x, w});
  }
  std::priority_queue<std::pair<double, int>, std::vector<std::pair<double, int>>, std::greater<>> q;
  std::vector<double> dis(n + 1, (double)inf), vis(n + 1);
  q.push({dis[1] = 0, 1});
  while (!q.empty()) {
    auto [d, u] = q.top(); q.pop();
    if (vis[u]) continue;
    vis[u] = true;
    for (auto &[v, w] : g[u]) {
      if (dis[v] > dis[u] + w) {
        dis[v] = dis[u] + w;
        q.push({dis[v], v});
      }
    }
  }
  double ans = dis[n] * dis[n] / t;
  std::cout << std::fixed << std::setprecision(20) << ans << '\n';
}

signed main() {
  freopen("M.in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}