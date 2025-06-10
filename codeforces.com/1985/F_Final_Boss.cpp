#include <bits/stdc++.h>
#define int long long

void solve() {
  int h, n;
  std::cin >> h >> n;
  std::vector<int> a(n + 1), c(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    std::cin >> c[i];
  }
  auto check = [&](int mid) -> bool {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
      sum += (mid + c[i] - 1) / c[i] * a[i];
      if (sum >= h) {
        return true;
      }
    }
    return false;
  };
  int l = 1, r = 1e13, ans = -1;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (check(mid)) r = mid - 1, ans = mid;
    else l = mid + 1;
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