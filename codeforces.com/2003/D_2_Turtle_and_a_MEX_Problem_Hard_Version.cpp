// date: 2025-03-21 15:11:06
// tag: 将mex和操作的性质（不会产生两个以上数）结合，得到类似于dag上dp的做法，以及mex通常和n一个数量级的性质，还有各种边角情况的处理
// dfs千万注意别忘了避免多次访问

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::multimap<int, int> mp;
  std::vector<std::pair<int, int>> v;
  int mx1 = 0, mx2 = 0;
  for (int i = 1; i <= n; i++) {
    int l;
    std::cin >> l;
    std::set<int> s;
    for (int j = 1; j <= l; j++) {
      int x;
      std::cin >> x;
      s.insert(x);
    }
    int mex1 = -1, mex2 = -1;
    for (int j = 0;; j++) {
      if (!s.count(j)) {
        if (mex1 == -1) mex1 = j;
        else if (mex2 == -1) mex2 = j;
        else break;
      }
    }
    v.push_back({mex1, mex2});
    mx2 = std::max(mex2, mx2);
    mx1 = std::max(mex1, mx1);
  }
  std::vector<std::vector<int>> g(mx2 + 1);
  for (auto [x, y] : v) {
    g[x].push_back(y);
  }
  std::vector<int> f(mx2 + 1);
  int mx3 = 0;
  auto dfs = [&](auto self, int u) -> void {
    if (f[u]) return;
    f[u] = u;
    for (int v : g[u]) {
      self(self, v);
      f[u] = std::max(f[u], f[v]);
    }
    if (g[u].size() >= 2) {
      mx3 = std::max(mx3, f[u]);
    }
  };
  for (int i = 0; i <= mx2; i++) {
    if (!f[i]) {
      dfs(dfs, i);
    }
  }
  int ans = std::max(0ll, (mx2 + m) * (m - mx2 + 1) / 2);
  // std::cerr << mx2 << '\n';
  for (int i = 0; i < std::min(mx2, m + 1); i++) {
    ans += std::max({mx1, mx3, f[i]});
    // std::cerr << ans << '\n';
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