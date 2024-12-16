#include <bits/stdc++.h>
#define int long long

void solve() {
  int k, l1, l2, r1, r2;
  std::cin >> k >> l1 >> r1 >> l2 >> r2;
  int t = 1;
  auto get = [](int l1, int r1, int l2, int r2) {
    if (r1 < l2 || l1 > r2) return 0ll;
    return r2 - l1;
  };
  int ans = 0;
  for (int i = 0; i < 62; i++) {
    if (t * l1 > r2) break;
    int l = l1, r = r1, ansl = -1;
    while (l <= r) {
      int mid = (l + r) / 2;
      if (mid * t >= l2) r = mid - 1, ansl = mid;
      else l = mid + 1;
    }
    l = l1, r = r1;
    int ansr = -1;
    while (l <= r) {
      int mid = (l + r) / 2;
      if (mid * t <= r2) l = mid + 1, ansr = mid;
      else r = mid - 1;
    }
    // std::cout << t << ' ' << ansl << ' ' << ansr << '\n';
    if (ansl != -1 && ansr != -1) {
      ans += ansr - ansl + 1;
    }
    t *= k;
  }
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