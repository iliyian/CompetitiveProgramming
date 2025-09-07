#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  std::vector<std::vector<int>> g(n + 1);
  for (int i = 2; i <= n; i++) {
    int x, y;
    std::cin >> x >> y;
    g[x].push_back(y);
  }
  int m;
  std::cin >> m;
  for (int i = 1; i <= m; i++) {
    int x, y;
    std::cin >> x >> y;
    g[x].push_back(y);
  }
  std::set<int> s;
  for (int i = 0; i < (1 << n); i++) {
    std::vector<int> vis(n + 1);
    auto dfs = [&](auto self, int u, int p) -> void {
      vis[u] = 1;
      for (int v : g[u]) {
        if (v != p) {
          self(self, v, u);
        }
      }
    };
    for (int j = 0; j < n; j++) {
      if (i >> j & 1) {
        dfs(dfs, j + 1, 0);
      }
    }
    int sum = 0;
    for (int j = 0; j < n; j++) {
      if (vis[j + 1]) {
        sum += a[j + 1];
      }
    }
    s.insert(sum);
  }
  // for (int i : s) {
  //   std::cerr << i << ' ';
  // }
  // std::cerr << '\n';
  std::cout << s.size() << '\n';
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