#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, t;
  std::cin >> n >> t;
  std::vector<std::array<int, 2>> a(n + 1);
  int now = 0;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i][0];
    now += a[i][0];
  }
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i][1];
  }
  std::sort(a.begin() + 1, a.end(), std::greater<>());
  if (now >= t) {
    std::cout << 0 << '\n';
    return;
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (now + a[i][0] * a[i][1] < t) {
      now += a[i][0] * a[i][1];
      ans += a[i][1];
    } else {
      int tmp = (t - now + a[i][0] - 1) / a[i][0];
      ans += tmp;
      std::cout << ans << '\n';
      return;
    }
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