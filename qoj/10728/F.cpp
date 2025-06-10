#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m, k;
  std::cin >> n >> m >> k;
  std::vector<int> col(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> col[i];
  }
  std::vector<std::vector<int>> g(n + 1);
  for (int i = 1; i <= m; i++) {
    int x, y;
    std::cin >> x >> y;
    g[x].push_back(y);
  }
  for (int c = 1; c <= 50; c++) {
    std::queue<std::array<int, 3>> q;
    std::vector<int> d1(n + 1, LLONG_MAX / 3);
    std::vector<int> d2(n + 1, LLONG_MAX / 3);
    std::vector<int> dv(n + 1, LLONG_MAX / 3);
    std::vector<int> vis(n + 1);
    for (int i = 1; i <= n; i++) {
      if (col[i] == c) {
        vis[i] = 1;
        dv[i] = i;
        q.push({1, i, i});
      }
    }
    while (!q.empty()) {
      auto [d, u, s] = q.front(); q.pop();
      for (int v : g[u]) {
        if (!vis[v]) {
          vis[v] = 1;
          dv[v] = s;
          q.push({d + 1, v, s});
        } else if (vis[v] == 1 && dv[v] != s) {
          vis[v] = 2;
          q.push({d + 1, v, s});
        }
        if (col[v] == c && v != s && d + 1 <= k) {
          std::cout << "NO\n";
          return;
        }
      }
    }
  }
  std::cout << "YES\n";
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