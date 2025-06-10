#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<std::set<int>> g(n + 1);
  int mx = -1, u, v;
  std::set<std::pair<int, int>> s;
  for (int i = 2; i <= n; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    g[x].insert(y);
    g[y].insert(x);
    if (w > mx) {
      mx = w;
      u = x, v = y;
    }
    s.insert(std::minmax(x, y));
  }
  for (auto i : g[u]) {
    if (!s.contains(std::minmax(v, i)) && i != v) {
      std::cout << i << ' ' << v << ' ' << 0 << '\n';
      return;
    }
  }
  for (auto i : g[v]) {
    if (!s.contains(std::minmax(u, i)) && i != u) {
      std::cout << i << ' ' << u << ' ' << 0 << '\n';
      return;
    }
  }
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