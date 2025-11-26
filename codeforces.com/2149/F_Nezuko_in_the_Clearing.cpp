#include <bits/stdc++.h>
#define int long long

void solve() {
  int h, d;
  std::cin >> h >> d;
  auto check = [&](int mid) -> bool {
    int r = mid - d + 1;
    int x = d / r, y = d % r;
    int s = x * (x + 1) / 2 * (r - y) + (x + 1) * (x + 2) / 2 * y;
    return s < h + r - 1;
  };
  int l = d, r = 5e9, ans = -1;
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