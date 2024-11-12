#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  if (n == 1) {
    std::cout << 1 << '\n';
    return;
  }
  int t = n;
  int ans = 0, lprv = 1, rprv = n, tmp = 0;
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      ans += (i - lprv) * n / lprv;
      // std::cout << ans << ' ';
      if (i * i != n) {
        ans += (rprv - n / i) * i;
      } else {
        tmp = rprv;
      }
      // std::cout << ans << '\n';
      lprv = i;
      rprv = n / i;
      // std::cout << lprv << ' ' << rprv << '\n';
    }
  }
  if (lprv != rprv) {
    ans += rprv * (rprv - lprv);
  } else {
    ans += (tmp - lprv) * lprv;
    // std::cout << rprv << ' ' << lprv << ' ' << tmp << '\n';
  }
  std::cout << ans + 1 << '\n';
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}