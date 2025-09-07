#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<std::vector<int>> g(n + 1);
  std::vector<int> cnt(n + 1);
  for (int i = 2; i <= n; i++) {
    int x, y;
    std::cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  if (n == 2) {
    std::cout << 0 << '\n';
    return;
  }
  for (int u = 1; u <= n; u++) {
    for (int v : g[u]) {
      if (g[v].size() == 1) {
        cnt[u]++;
      }
    }
  }
  int tot = 0;
  for (int i = 1; i <= n; i++) {
    if (g[i].size() == 1) {
      tot++;
    }
  }
  int ans = LLONG_MAX / 3;
  for (int i = 1; i <= n; i++) {
    ans = std::min(ans, tot - cnt[i]);
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