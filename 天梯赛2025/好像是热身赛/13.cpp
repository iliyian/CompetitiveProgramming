#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m, s, t;
  std::cin >> n >> m >> s >> t;
  std::vector<std::vector<std::pair<int, int>>> g(n + 1);
  std::vector<int> a(n + 1), p(n + 1), lv(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    p[i] = i;
  }
  a[s] = 0, a[t] = 0;
  std::sort(p.begin() + 1, p.end(), [&](const int &x, const int &y) {
    return a[x] < a[y];
  });
  for (int i = 1; i <= n; i++) {
    lv[p[i]] = i;
  }
  for (int i = 1; i <= m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    g[x].push_back({y, w});
    g[y].push_back({x, w});
  }
  int mind = LLONG_MAX / 3, mxh = LLONG_MAX / 3;
  for (int i = 1; i <= n; i++) {
    std::vector<int> dis(n + 1, LLONG_MAX / 3);
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> q;
    q.push({dis[s] = 0, s});
    while (!q.empty()) {
      auto [d, u] = q.top(); q.pop();
      if (dis[u] != d) continue;
      for (auto [v, w] : g[u]) {
        if (lv[v] <= i) {
          if (dis[v] > dis[u] + w) {
            q.push({dis[v] = dis[u] + w, v});
          }
        }
      }
    }
    if (std::tie(dis[t], a[p[i]]) < std::tie(mind, mxh)) {
      mind = dis[t], mxh = a[p[i]];
    }
  }
  if (mind == LLONG_MAX / 3) {
    std::cout << "Impossible";
  } else {
    std::cout << mind << ' ' << mxh;
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