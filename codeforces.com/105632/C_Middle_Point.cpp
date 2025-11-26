#include <bits/stdc++.h>
// #define int long long

void solve() {
  int a, b, tx, ty;
  std::cin >> a >> b >> tx >> ty;
  std::vector<std::array<int, 4>> ans;
  for (int i = 0; i < 100; i++) {
    if ((tx == 0 || tx == a) && (ty == 0 || ty == b)) {
      std::cout << ans.size() << '\n';
      std::ranges::reverse(ans);
      for (auto [u, v, s, t] : ans) {
        std::cout << u << ' ' << v << ' ' << s << ' ' << t << '\n';
      }
      return;
    }
    // std::cerr << tx << ' ' << ty << '\n';
    int xx = tx * 2, yy = ty * 2;
    int u = xx, v = yy, s = 0, t = 0;
    if (u > a) {
      u -= a, s = a;
    }
    if (v > b) {
      v -= b, t = b;
    }
    ans.push_back({u, v, s, t});
    tx = u, ty = v;
  }
  std::cout << -1 << '\n';
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