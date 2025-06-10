// date: 2025-04-06 23:35:26
// tag: 基于贪心技巧的dp

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, k;
  std::cin >> n >> k;
  std::vector<int> a(n + 1);
  int ans = LLONG_MAX / 3;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  a[0] = LLONG_MAX / 3;
  std::vector<std::vector<int>> f(n + 1, std::vector<int>(k + 1, LLONG_MAX / 3));
  f[0][0] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= k; j++) {
      int mn = a[i];
      for (int t = 0; t <= std::min(j, i - 1); t++) {
        mn = std::min(mn, a[i - t]);
        f[i][j] = std::min(f[i][j], f[i - t - 1][j - t] + (t + 1) * mn);
      }
    }
  }
  for (int i = 0; i <= k; i++) {
    ans = std::min(f[n][i], ans);
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