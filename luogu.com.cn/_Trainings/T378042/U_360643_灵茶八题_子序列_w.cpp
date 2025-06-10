#include <bits/stdc++.h>
#define int long long

constexpr int N = 1 << 16;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  std::vector<int> dp(N);
  int ans = 0;
  dp[0] = 1;
  for (int i = 1; i <= n; i++) {
    auto ndp = dp;
    for (int j = 0; j + a[i] < N; j++) {
      if (dp[j]) {
        ndp[j + a[i]] += dp[j];
        // std::cerr << j << ' ' << dp[j] << '\n';
      }
    }
    // std::cerr << '\n';
    dp = ndp;
  }
  for (int i = 0; i < N; i++) {
    if (dp[i] % 2) {
      ans ^= i;
      // std::cerr << i << ' ' << dp[i] << '\n';
    }
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