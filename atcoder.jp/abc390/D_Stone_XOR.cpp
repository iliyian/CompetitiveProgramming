#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  std::unordered_set<int> ans;
  // int x = 0;
  int y = 0;
  std::vector<int> val(n);
  auto dfs = [&](auto self, int u, int v) -> void {
    if (u == n) {
      // int y = 0;
      // for (int i = 0; i < v; i++) {
      //   y ^= val[i];
      // }
      ans.insert(y);
      return;
    }
    int cur = 0;
    for (int i = 0; i <= v; i++) {
      y ^= val[i];
      val[i] += a[u];
      y ^= val[i];
      if (i < v) {
        self(self, u + 1, v);
      } else {
        self(self, u + 1, v + 1);
      }
      y ^= val[i];
      val[i] -= a[u];
      y ^= val[i];
    }
  };
  dfs(dfs, 0, 0);
  std::cout << ans.size() << '\n';
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