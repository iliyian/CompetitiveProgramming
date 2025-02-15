#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<int> prv;
  prv.push_back(-9);
  int ans = 0;
  auto dfs = [&](auto self, int u, bool f) -> void {
    if (u == n + 1) {
      ans++;
      if (f) {
        for (int i = 1; i < prv.size(); i++) {
          std::cout << prv[i] << ' ';
        }
        std::cout << '\n';
      }
      return;
    }
    for (int i = prv.back() + 10; i <= m - (n - u) * 10; i++) {
      prv.push_back(i);
      self(self, u + 1, f);
      prv.pop_back();
    }
  };
  dfs(dfs, 1, 0);
  std::cout << ans << '\n';
  dfs(dfs, 1, 1);
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