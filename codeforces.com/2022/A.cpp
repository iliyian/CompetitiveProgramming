#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, r;
  std::cin >> n >> r;
  std::vector<int> a(n + 1);
  int tot = r * 2, ans = 0;
  int rest = 0;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    tot -= a[i] / 2 * 2;
    ans += a[i] / 2 * 2;
    a[i] %= 2;
    rest += a[i];
  }
  ans += std::min(tot - rest, rest);
  std::cout << ans << '\n';
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}