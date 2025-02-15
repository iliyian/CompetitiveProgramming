#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<std::set<int>> g(n + 1);
  std::vector<int> p(n + 1);
  for (int i = 2; i <= n; i++) {
    int x, y;
    std::cin >> x >> y;
    g[x].insert(y);
    g[y].insert(x);
  }
  std::iota(p.begin(), p.end(), 0);
  std::sort(p.begin() + 1, p.end(), [&](const int &x, const int &y) {
    return g[x].size() < g[y].size();
  });
  if (n == 2) {
    std::cout << 0 << '\n';
    return;
  }
  int ans = 0;
  for (int i = n; i >= std::max(1ll, n - 400); i--) {
    for (int j = i - 1; j >= std::max(1ll, n - 400); j--) {
      ans = std::max<int>(ans, g[p[i]].size() + g[p[j]].size() - (g[p[i]].count(p[j]) ? 2 : 1));
      // std::cout << g[p[i]].size() << ' ' << g[p[j]].size() << '\n';
    }
  }
  std::cout << ans << '\n';
  // std::cout << 4 << '\n';
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}