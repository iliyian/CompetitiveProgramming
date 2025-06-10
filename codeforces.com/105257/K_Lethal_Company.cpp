// date: 2025-03-03 21:38:39
// tag: 

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m, k;
  std::cin >> n >> m >> k;
  std::set<int> s;
  std::vector<std::array<int, 3>> a(m + 1);
  for (int i = 1; i <= m; i++) {
    std::cin >> a[i][0] >> a[i][1] >> a[i][2];
    s.insert(a[i][1]);
  }
  std::sort(a.begin() + 1, a.end(), std::greater<>());
  auto check = [&](int mid) -> bool {
    int need = 0;
    std::vector<int> b(n + 1);
    for (int i = 1; i <= m; i++) {
      auto [t, x, y] = a[i];
      if (t > mid) continue;
      int req = mid - t + 1 - (y - 1) / k;
      if (b[x] < req) {
        need += req - b[x];
        b[x] = req;
        if (need > mid - t + 1) {
          return false;
        }
      }
    }
    // for (int i = 1; i <= n; i++) {
    //   cur += b[i];
    //   if (cur > mid) return false;
    // }
    // std::cerr << mid << ' ' << cur << '\n';
    return true;
  };
  if (s.size() == 1) {
    std::cout << -1 << '\n';
    return;
  }
  int l = 0, r = LLONG_MAX / 3, ans = -1;
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
  // std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}