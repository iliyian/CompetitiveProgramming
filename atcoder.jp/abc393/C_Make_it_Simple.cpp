#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m;
  std::cin >> n >> m;
  int ans = 0;
  std::vector<std::set<int>> g(n + 1);
  for (int i = 1; i <= m; i++) {
    int x, y;
    std::cin >> x >> y;
    if (x == y || g[x].count(y) || g[y].count(x)) {
      ans++;
    } else {
      g[x].insert(y);
      g[y].insert(x);
    }
  }
  std::cout << ans << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  // std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}