#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  int sum = 0;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    if (i % 2) sum += a[i];
    else sum -= a[i];
  }
  // std::cerr << sum << '\n';
  int ans = sum + (n % 2 ? n - 1 : n - 2);
  int mn = -a[1] * 2 - 1, mx = LLONG_MIN;
  for (int i = 2; i <= n; i++) {
    if (i % 2 == 0) {
      mx = std::max(mx, a[i] * 2 - i);
      int now = sum + a[i] * 2 + i + mn;
      ans = std::max(ans, now);
      // std::cerr << mn << '\n';
    } else {
      mn = std::max(mn, -a[i] * 2 - i);
      int now = sum - a[i] * 2 + i + mx;
      ans = std::max(ans, now);
    }
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