// date: 2025-04-29 20:06:00
// tag: 典中典之按位拆分

#include <bits/stdc++.h>
#define int long long

int mod = 998244353;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  int ans = 0;
  for (int i = 0; i <= 30; i++) {
    int cur = 0;
    int s[2] {}, c[2] {};
    c[0] = 1;
    for (int j = 1; j <= n; j++) {
      int idx = a[j] >> i & 1;
      cur ^= idx;
      s[cur] += j;
      s[cur] %= mod;
      c[cur]++;
      ans += (c[cur ^ 1] * j % mod - s[cur ^ 1] + mod) % mod * ((1ll << i) % mod) % mod;
      ans %= mod;
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