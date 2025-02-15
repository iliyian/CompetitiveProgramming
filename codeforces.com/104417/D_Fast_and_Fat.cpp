#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<std::pair<int, int>> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i].first >> a[i].second;
  }
  std::sort(a.begin() + 1, a.end(), [&](const std::pair<int, int> &x, const std::pair<int, int> &y) {
    return x.first + x.second < y.first + y.second;
  });
  auto check = [&](int mid) {
    int cnt = 0, mn = LLONG_MAX;
    std::vector<std::pair<int, int>> b;
    for (int i = 1; i <= n; i++) {
      if (a[i].first < mid) {
        b.push_back(a[i]);
      } else {
        if (!b.empty()) {
          mn = std::min(mn, a[i].first - std::max(0ll, b.back().second - a[i].second));
          b.pop_back();
        }
      }
    }
    if (!b.empty() || mn < mid) return false;
    return true;
  };
  int l = 1, r = INT_MAX, ans = -1;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (check(mid)) l = mid + 1, ans = mid;
    else r = mid - 1;
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