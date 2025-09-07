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
    std::vector<int> in1(n + 1, LLONG_MAX / 3), in2(n + 1, LLONG_MAX / 3), in1v(n + 1, LLONG_MAX / 3);
    std::vector<int> vis(n + 1);
    for (int i = 1; i <= n; i++) {
      if (col[i] == c) {
        vis[i] = 1;
        in1[i] = 1, in1v[i] = i;
        q.push({1, i, i});
      }
    }
    while (!q.empty()) {
      auto [d, u, s] = q.front(); q.pop();
      for (int v : g[u]) {
        if (col[v] != c) {
          if (vis[v] == 0) {
            vis[v] = 1;
            in1v[v] = s, in1[v] = d + 1;
            q.push({d + 1, v, s});
          } else if (vis[v] == 1) {
            if (in1v[v] == s) {
              continue;
            }
            vis[v] = 2;
            in2[v] = d + 1;
            q.push({d + 1, v, s});
          }
        } else {
          if (v != s && d + 1 <= k) {
            std::cout << "NO\n";
            return;
          }
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