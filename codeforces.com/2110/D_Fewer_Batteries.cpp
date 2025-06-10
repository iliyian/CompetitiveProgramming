#include <bits/stdc++.h>
#define int long long

std::mt19937 rd(std::random_device{}());

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<int> b(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> b[i];
  }
  std::vector<std::vector<std::pair<int, int>>> g(n + 1);
  for (int i = 1; i <= m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    g[x].push_back({y, w});
  }
  for (int i = 1; i <= n; i++) {
    std::shuffle(g[i].begin(), g[i].end(), rd);
  }
  auto check = [&](int mid) {
    std::vector<int> dis(n + 1, LLONG_MIN / 3);
    std::queue<std::pair<int, int>> q;
    q.push({dis[1] = b[1], 1});
    while (!q.empty()) {
      auto [d, u] = q.front(); q.pop();
      if (u == n) return true;
      if (dis[u] != d) continue;
      for (auto [v, w] : g[u]) {
        if (w > mid || w > d) continue;
        if (dis[v] < dis[u] + b[v]) {
          q.push({dis[v] = dis[u] + b[v], v});
        }
      }
    }
    return dis[n] != LLONG_MIN / 3;
  };
  int l = 0, r = 1e9 + 10, ans = -1;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (check(mid)) r = mid - 1, ans = mid;
    else l = mid + 1;
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