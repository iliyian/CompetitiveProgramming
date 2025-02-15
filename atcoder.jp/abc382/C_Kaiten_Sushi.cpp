#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::pair<int, int>> a;
  for (int i = 1; i <= n; i++) {
    int x;
    std::cin >> x;
    if (a.empty() || x < a.back().first) {
      a.push_back({x, i});
    }
  }
  for (int i = 1; i <= m; i++) {
    int x;
    std::cin >> x;
    int l = 0, r = a.size() - 1, ans = -1;
    while (l <= r) {
      int mid = (l + r) / 2;
      if (a[mid].first <= x) r = mid - 1, ans = a[mid].second;
      else l = mid + 1;
    }
    std::cout << ans << '\n';
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