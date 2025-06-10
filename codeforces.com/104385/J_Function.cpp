#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  int q;
  std::cin >> q;
  int sn = sqrtl(n);
  while (q--) {
    int op, x, y;
    std::cin >> op;
    if (op == 0) {
      std::cin >> x >> y;
      a[x] = std::min(a[x], y);
    } else {
      std::cin >> x;
      int ans = LLONG_MAX;
      for (int i = std::max(1ll, x - sn - 10); i <= std::min(n, x + sn + 10); i++) {
        ans = std::min(ans, (x - i) * (x - i) + a[i]);
      }
      std::cout << ans << '\n';
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