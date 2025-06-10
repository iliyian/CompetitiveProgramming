#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, p;
  std::cin >> n >> p;
  int l = 1, r = 1e9 + 10, ans = -1;
  std::vector<int> a(n + 1), b(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i] >> b[i];
  }
  auto check = [&](int mid) -> bool {
    int mx = 0, cur = 0;
    std::vector<int> f(n + 1);
    for (int i = 1; i <= n; i++) {
      if (b[i] <= mid) {
        f[i] = std::max(f[i - 1] + a[i], a[i]);
      } else {
        f[i] = 0;
      }
      mx = std::max(mx, f[i]);
    }
    return mx >= p;
  };
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