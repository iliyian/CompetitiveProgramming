// date: 2025-03-27 16:31:48
// tag: 典中典之分类讨论

#include <bits/stdc++.h>
#define int long long

constexpr int mod = 998244353;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1), s(n + 1), p(n + 1);
  p[0] = 1;
  int mn = 0;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    s[i] = s[i - 1] + a[i];
    p[i] = p[i - 1] * 2 % mod;
    mn = std::min(mn, s[i]);
  }
  if (mn >= 0) {
    std::cout << p[n] << '\n';
    return;
  }
  int ans = 0, cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (s[i] == mn) {
      ans += p[n - i] * p[cnt] % mod;
      ans %= mod;
    }
    cnt += s[i] >= 0;
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