#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<int> a(n + 1), g(1 << m);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  for (int i = 0; i < (1 << m); i++) {
    std::cin >> g[i];
  }
  std::vector<std::array<int, 3>> f;
  f.push_back({0, 0, (1 << m) - 1});
  for (int i = 1; i <= n; i++) {
    int val = LLONG_MIN;
    for (auto &[v, sor, sand] : f) {
      sor |= a[i];
      sand &= a[i];
      val = std::max(val, v + g[sor - sand]);
      // std::cerr << v << ' ' << g[sor - sand] << '\n';
    }
    auto cur = f;
    f.clear();
    for (auto [v, sor, sand] : cur) {
      if (f.empty() || sor != f.back()[1] || sand != f.back()[2]) {
        f.push_back({v, sor, sand});
      } else {
        f.back()[0] = std::max(f.back()[0], v);
      }
    }
    f.push_back({val, 0, (1 << m) - 1});
    if (i == n) {
      std::cout << val << '\n';
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