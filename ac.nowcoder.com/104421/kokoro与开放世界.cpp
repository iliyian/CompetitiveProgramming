#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m, k;
  std::cin >> n >> m >> k;
  std::vector<std::vector<std::pair<int, int>>> g(n + k * 2 + 1);
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    g[i].push_back({a[i] + n, 0});
  }
  for (int i = 1; i <= m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    g[x].push_back({y, w});
  }
  int p;
  std::cin >> p;
  for (int i = 1; i <= p; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    g[x + n].push_back({y + n + k, w});
  }
  for (int i = 1; i <= n; i++) {
    int h;
    std::cin >> h;
    g[a[i] + n + k].push_back({i, h});
  }
  std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> q;
  std::vector<int> dis(n + k * 2 + 1, LLONG_MAX / 3);
  q.push({dis[1] = 0, 1});
  while (!q.empty()) {
    auto [d, u] = q.top(); q.pop();
    if (dis[u] != d) continue;
    for (auto [v, w] : g[u]) {
      if (dis[v] > dis[u] + w) {
        dis[v] = dis[u] + w;
        q.push({dis[v], v});
      }
    }
  }
  std::cout << (dis[n] == LLONG_MAX / 3 ? -1 : dis[n]) << '\n';
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