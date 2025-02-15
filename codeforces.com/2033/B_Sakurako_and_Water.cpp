#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<std::vector<int>> a(n + 1, std::vector<int>(n + 1));
  std::vector<int> mn(n * 2, LLONG_MAX);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      std::cin >> a[i][j];
      mn[i - j + n] = std::min(mn[i - j + n], a[i][j]);
    }
  }
  int ans = 0;
  for (int i = 1; i <= n * 2 - 1; i++) {
    ans += std::max(-mn[i], 0ll);
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