// date: 2024-07-01 14:20:19
// tag: 数论，贪心

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1), b(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i] >> b[i];
  }
  int lcm = 1, gcd = 0, ans = 1;
  for (int i = 1; i <= n; i++) {
    lcm = std::lcm(lcm, b[i]);
    gcd = std::gcd(gcd, a[i] * b[i]);
    if (gcd % lcm) {
      ans++;
      lcm = b[i], gcd = a[i] * b[i];
    }
  }
  std::cout << ans << '\n';
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("C.in", "r", stdin);
  freopen("C.out", "w", stdout);

  int _;
  std::cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}