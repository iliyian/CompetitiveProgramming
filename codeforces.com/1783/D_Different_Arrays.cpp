// date: 2025-04-09 22:17:34
// tag: 控制值域，控制一切。无前效性。无后效性。子结构。似乎是相同的概念？

#include <bits/stdc++.h>
#define int long long

constexpr int mod = 998244353;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  int sum = 0;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    if (i >= 2) {
      sum += a[i];
    }
  }
  std::vector<int> dp(sum * 2 + 1);
  dp[sum + a[2]] = 1;
  // std::map<int, int> dp;
  // dp[a[2]] = 1;
  for (int i = 3; i <= n; i++) {
    std::vector<int> ndp(sum * 2 + 1);
    // std::map<int, int> ndp;
    // for (int j = 0; j <= sum * 2; j++) {
    for (int j = -sum; j <= sum; j++) {
      if (j - a[i] + sum >= 0 && j - a[i] + sum <= sum * 2) {
        ndp[j + sum] += dp[j + sum - a[i]];
        ndp[j + sum] %= mod;
      }
      if (j != a[i]) {
        if (a[i] - j + sum >= 0 && a[i] - j + sum <= sum * 2) {
          ndp[j + sum] += dp[a[i] - j + sum];
          ndp[j + sum] %= mod;
        }
      }
    }
    // for (int i = -sum; i <= sum; i++) {
    //   // ans += dp[i];
    //   if (dp[i]) {
    //     std::cerr << i - sum << ' ';
    //   }
    // }
    // std::cerr << '\n';
    dp = ndp;
  }
  int ans = 0;
  // for (int i = 0; i <= sum * 2; i++) {
  for (int i = -sum; i <= sum; i++) {
    ans += dp[i + sum];
    ans %= mod;
    // if (dp[i]) {
    //   std::cerr << i - sum << '\n';
    // }
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