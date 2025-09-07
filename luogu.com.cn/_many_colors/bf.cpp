#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1), in(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  std::vector<std::vector<int>> g(n + 1);
  for (int i = 2; i <= n; i++) {
    int x, y;
    std::cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
    in[x]++, in[y]++;
  }
  std::vector<int> leaf, dep(n + 1), pa(n + 1);
  for (int i = 1; i <= n; i++) {
    if (in[i] == 1) {
      leaf.push_back(i);
    }
  }
  auto dfs = [&](auto self, int u, int p) -> void {
    dep[u] = dep[p] + 1;
    pa[u] = p;
    for (int v : g[u]) {
      if (v != p) {
        self(self, v, u);
      }
    }
  };
  dfs(dfs, 1, 0);
  auto calc = [&](int x, int y) -> int {
    std::set<int> s;
    while (x != y) {
      if (dep[x] < dep[y]) std::swap(x, y);
      s.insert(a[x]);
      x = pa[x];
    }
    s.insert(a[x]);
    return s.size();
  };
  int ans = 0, ansx = -1, ansy = -1;
  for (int i = 0; i < leaf.size(); i++) {
    for (int j = i + 1; j < leaf.size(); j++) {
      int x = leaf[i], y = leaf[j], now = calc(x, y);
      if (ans < now) {
        ans = now;
        ansx = x, ansy = y;
      }
    }
  }
  std::cout << ans << '\n';
  // std::cerr << ansx << ' ' << ansy << '\n';
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