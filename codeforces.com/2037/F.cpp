// date: 2024-12-01 23:17:56
// tag: 有趣的二分扫描线，把判定问题转换为区间问题，再转换为区间计数问题

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m, k;
  std::cin >> n >> m >> k;
  std::vector<int> h(n + 1), x(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> h[i];
  }
  for (int i = 1; i <= n; i++) {
    std::cin >> x[i];
  }

  auto check = [&](int mid) -> bool {
    std::vector<std::pair<int, int>> vec;
    for (int i = 1; i <= n; i++) {
      int l = x[i] - m + (h[i] + mid - 1) / mid;
      int r = x[i] + m - (h[i] + mid - 1) / mid;
      if (l > r) continue;
      vec.push_back({l, 1});
      vec.push_back({r + 1, -1});
    }
    std::sort(vec.begin(), vec.end());
    int cur = 0;
    for (auto [x, i] : vec) {
      cur += i;
      if (cur >= k) {
        return true;
      }
    }
    return false;
  };

  int l = 1, r = 1e10, ans = -1;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (check(mid)) r = mid - 1, ans = mid;
    else l = mid + 1;
  }
  std::cout << ans << '\n';
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}