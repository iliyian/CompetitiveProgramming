#include <bits/stdc++.h>
#define int long long

void solve() {
  int a[13];
  int sa = 0, sb = 0;
  for (int i = 0; i < 13; i++) {
    std::cin >> a[i];
    sa += a[i], sb += a[i] / 3;
  }
  auto check = [&](int mid) -> bool {
    int l = 0, r = 0;
    for (int i = 0; i < 13; i++) {
      int L = (std::max(0ll, a[i] + 3 * mid - sa) + 1) / 2;
      int R = a[i] / 3;
      if (L > R) return false;
      l += L, r += R;
    }
    return l <= mid && mid <= r;
  };
  int l = 0, r = sa / 4, ans = 0;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (check(mid)) l = mid + 1, ans = mid;
    else r = mid - 1;
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