#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, k;
  std::cin >> n >> k;
  std::vector<std::vector<int>> a(n + 1, std::vector<int>(k + 1));
  std::vector<std::vector<int>> f(n + 1, std::vector<int>(k + 1, LLONG_MAX / 3));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= k; j++) {
      std::cin >> a[i][j];
    }
  }
  std::fill(f[0].begin() + 1, f[0].end(), 0);
  for (int i = 1; i <= n; i++) {
    int mx = 0;
    for (int j = 1; j <= k; j++) {
      mx = std::max(mx, f[i - 1][j]);
      f[i][j] = a[i][j] + mx;
    }
  }
  int ans = 0;
  for (int i = 1; i <= k; i++) {
    ans = std::max(ans, f[n][i]);
  }
  std::cout << ans << "\n";
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