#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, x, y;
  std::cin >> n;
  std::vector<std::pair<int, int>> a(n + 1);
  int mn = 2e9;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i].first >> a[i].second;
    mn = std::min(mn, a[i].second);
  }
  std::sort(a.begin() + 1, a.end());
  std::vector<std::pair<int, int>> ans;
  int px = -1, py = -1;
  ans.push_back({a[1].first, mn - 1});
  for (int i = 1; i <= n; i++) {
    auto [x, y] = a[i];
    if (x != px && px != -1) {
      ans.push_back({px + 1, mn});
    }
    px = x;
    py = y;
    ans.push_back({x, y});
  }
  ans.push_back({px + 1, mn});
  std::cout << ans.size() << '\n';
  for (auto [x, y] : ans) {
    std::cout << x << ' ' << y << '\n';
  }
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