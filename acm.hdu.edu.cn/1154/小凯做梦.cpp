#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<std::vector<std::pair<int, int>>> g(n + 1);
  for (int i = 2; i <= n; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    w %= 2;
    g[x].push_back({y, w});
    g[y].push_back({x, w});
  }
  std::vector<int> dis(n + 1);
  int cnt[2] {};
  auto dfs = [&](auto self, int u, int p) -> void {
    cnt[dis[u]]++;
    for (auto [v, w] : g[u]) {
      if (v != p) {
        dis[v] = dis[u] + w;
        dis[v] %= 2;
        self(self, v, u);
      }
    }
  };
  dfs(dfs, 1, 0);
  // std::cerr << cnt[0] << ' ' << cnt[1] << '\n';
  int ans = n;
  for (int i = 0; i < 2; i++) {
    if (cnt[i] >= 3) ans += cnt[i] * (cnt[i] - 1) * (cnt[i] - 2);
    if (cnt[i] >= 2) ans += cnt[i] * (cnt[i] - 1) * 3;
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