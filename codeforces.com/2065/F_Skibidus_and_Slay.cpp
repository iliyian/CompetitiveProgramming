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
  std::vector<int> ans(n + 1);
  for (int i = 2; i <= n; i++) {
    int x, y;
    std::cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
    if (a[x] == a[y]) {
      ans[a[x]] = 1;
    }
  }
  auto dfs = [&](auto self, int u, int p) -> void {
    std::set<int> s;
    if (p) {
      s.insert(a[p]);
    }
    for (int v : g[u]) {
      if (v != p) {
        if (s.count(a[v])) {
          ans[a[v]] = 1;
        }
        s.insert(a[v]);
        self(self, v, u);
      }
    }
  };
  dfs(dfs, 1, 0);
  for (int i = 1; i <= n; i++) {
    std::cout << ans[i];
  }
  std::cout << '\n';
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