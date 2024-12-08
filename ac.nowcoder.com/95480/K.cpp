#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m, k;
  std::cin >> n >> m >> k;
  std::vector<std::pair<int, int>> a(k + 1);
  for (int i = 1; i <= k; i++) {
    std::cin >> a[i].first >> a[i].second;
  }
  int mnx = 1, mny = 1, ans = INT_MIN;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      int sum = INT_MAX;
      for (int u = 1; u <= k; u++) {
        int d = std::abs(a[u].first - i) + std::abs(a[u].second - j);
        sum = std::min(sum, d);
      }
      if (sum > ans) {
        ans = sum;
        mnx = i, mny = j;
      }
    }
  }
  std::cout << ans << '\n' << mnx << ' ' << mny << '\n';
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  // std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}