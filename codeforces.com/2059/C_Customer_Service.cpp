#include <algorithm>
#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<std::vector<int>> a(n + 1, std::vector<int>(n + 1));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      std::cin >> a[i][j];
    }
    for (int j = n - 1; j >= 1; j--) {
      a[i][j] += a[i][j + 1];
    }
    // for (int j = 1; j <= n; j++) {
    //   std::cerr << a[i][j] << " \n"[j == n];
    // }
  }
  std::vector<std::vector<std::pair<int, int>>> pos(n + 1);
  for (int i = 1; i <= n; i++) {
    for (int j = n; j >= 1; j--) {
      if (a[i][j] >= n) break;
      pos[a[i][j]].push_back({j, i});
    }
  }
  for (int i = 1; i < n; i++) {
    std::sort(pos[i].begin(), pos[i].end());
  }
  std::set<int> s;
  int ans = 0;
  auto dfs = [&](auto self, int v, int y) -> void {
    ans = std::max(ans, v);
    // std::cerr << v << ' ' << y << '\n';
    if (v == n) return;
    auto p = std::lower_bound(pos[v].begin(), pos[v].end(), std::pair{y, 0}) - pos[v].begin() - 1;
    // for (int i = 0; i <= p; i++) {
    for (int i = p; i >= 0; i--) {
    // {
      // if (p == pos[v].size() || p < 0) return;
      auto [y, x] = pos[v][i];
      if (y != pos[v][p].first) return;
      // std::cerr << y << '\n';
      if (!s.count(x)) {
        s.insert(x);
        self(self, v + 1, y);
        s.erase(x);
      }
    }
    // }
  };
  dfs(dfs, 1, n + 1);
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