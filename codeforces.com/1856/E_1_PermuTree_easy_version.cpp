// date: 2025-04-10 08:07:07
// tag: 竟然是少见的树上背包，有趣有趣

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<std::vector<int>> g(n + 1);
  std::vector<int> a(n + 1);
  for (int i = 2; i <= n; i++) {
    int x;
    std::cin >> x;
    g[x].push_back(i);
  }
  std::vector<int> siz(n + 1), dep(n + 1);
  dep[1] = 1;
  int ans = 0;
  auto dfs = [&](auto self, int u) -> void {
    siz[u] = 1;
    std::vector<int> vec;
    for (int v : g[u]) {
      dep[v] = dep[u] + 1;
      self(self, v);
      siz[u] += siz[v];
      vec.push_back(siz[v]);
    }
    std::vector<int> f(siz[u]);
    f[0] = 1;
    // std::cerr << u << '\n';
    for (auto i : vec) {
      // std::cerr << i << ' ';
      for (int j = siz[u] - 1; j >= i; j--) {
        f[j] |= f[j - i];
      }
    }
    // std::cerr << '\n';
    int mx = 0;
    for (int i = 1; i <= siz[u] - 1; i++) {
      if (f[i]) {
        // std::cerr << i << ' ' << siz[u] - 1 - i << '\n';
        mx = std::max(mx, i * (siz[u] - 1 - i));
      }
    }
    ans += mx;
    // std::cerr << u << ' ' << mx << '\n';
  };
  dfs(dfs, 1);
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