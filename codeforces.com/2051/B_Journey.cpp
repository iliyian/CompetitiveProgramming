#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  int a[4] {};
  std::cin >> n >> a[1] >> a[2] >> a[3];
  a[2] += a[1];
  a[3] += a[2];
  int l = 1, r = 1e9, ans = -1;
  while (l <= r) {
    int mid = (l + r) / 2;
    int sum = mid / 3 * a[3] + a[mid % 3];
    if (sum >= n) r = mid - 1, ans = mid;
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