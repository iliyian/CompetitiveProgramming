#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  std::vector<int> lc(n + 1), rc(n + 1);
  for (int i = 1; i <= n; i++) {
    if (i % 2 == 0) {
      lc[i / 2] = i;
    } else {
      rc[i / 2] = i;
    }
  }
  int tot = 0;
  std::vector<int> ans(n + 1);
  auto dfs = [&](auto self, int u) {
    if (!u) return;
    self(self, lc[u]);
    self(self, rc[u]);
    ans[u] = a[++tot];
  };
  dfs(dfs, 1);
  for (int i = 1; i <= n; i++) {
    std::cout << ans[i];
    if (i != n) {
      std::cout << ' ';
    }
  }
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