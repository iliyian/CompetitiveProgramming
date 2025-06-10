// date: 2025-03-02 11:13:30
// tag: 十分巧妙的利用异或的奇偶性的思想。非简单路径的树上异或最大权值

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, q;
  std::cin >> n >> q;
  std::vector<int> d(31);
  auto add = [&](int x) {
    for (int i = 30; i >= 0; i--) {
      if (x >> i & 1) {
        if (d[i]) {
          x ^= d[i];
        } else {
          d[i] = x;
          return;
        }
      }
    }
  };
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  std::vector<std::vector<int>> g(n + 1);
  for (int i = 2; i <= n; i++) {
    int x, y;
    std::cin >> x >> y;
    add(a[x] ^ a[y]);
    g[x].push_back(y);
    g[y].push_back(x);
  }
  std::vector<int> col(n + 1);
  auto dfs = [&](auto self, int u, int p) -> void {
    col[u] = col[p] ^ 1;
    for (int v : g[u]) {
      if (v != p) {
        self(self, v, u);
      }
    }
  };
  dfs(dfs, 1, 0);
  int ans2 = 0, ans1 = 0;
  for (int i = 30; i >= 0; i--) {
    ans2 = std::max(ans2, ans2 ^ d[i]);
  }
  for (int i = 1; i <= n; i++) {
    int cur = a[i];
    for (int j = 30; j >= 0; j--) {
      cur = std::max(cur, cur ^ d[j]);
    }
    ans1 = std::max(ans1, cur);
  }
  // std::cerr << ans2 << ' ' << ans1 << '\n';
  while (q--) {
    int x, y;
    std::cin >> x >> y;
    if (col[x] ^ col[y]) {
      std::cout << ans2 << '\n';
    } else {
      std::cout << ans1 << '\n';
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