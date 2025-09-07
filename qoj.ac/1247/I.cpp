// date: 2024-10-25 08:21:36
// tag: 

#include <bits/stdc++.h>

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::array<int, 3>> a;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      int x;
      std::cin >> x;
      a.push_back({x, i, j});
    }
  }
  std::sort(a.begin(), a.end());
  auto check = [&](int mid) {
    std::vector<std::array<int, 3>> b(mid);
    std::copy(a.begin(), a.begin() + mid, b.begin());
    std::sort(b.begin(), b.end(), [&](const std::array<int, 3>& x, const std::array<int, 3>& y) {
      return std::tie(x[1], x[2]) < std::tie(y[1], y[2]);
    });
    for (int i = 1; i < mid; i++) {
      if (b[i][1] < b[i - 1][1] || b[i][2] < b[i - 1][2]) {
        return false;
      }
    }
    return true;
  };
  int l = 1, r = n * m, ans = - 1;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (check(mid)) l = mid + 1, ans = mid;
    else r = mid - 1;
  }
  std::cout << ans << '\n';
}

signed main() {
  freopen("I.in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}