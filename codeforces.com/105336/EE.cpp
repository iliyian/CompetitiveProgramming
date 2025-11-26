#include <bits/stdc++.h>
#define int long long

constexpr int mod = 998244353;

int qpow(int a, int b) {
  int ans = 1;
  while (b) {
    if (b & 1) ans = ans * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return ans;
}

void solve() {
  int n, m;
  std::cin >> n >> m;
  int ans1 = 1, threshold = 26, t = m;
  for (int i = 1; i <= n; i++) {
    if (i > threshold) {
      threshold *= 26;
      t--;
    }
    ans1 += std::max(t, 0ll);
    ans1 %= mod;
  }
  int inv26 = qpow(26, mod - 2), inv = 1, ans2 = 0, p = 1;
  for (int i = 0; i <= m; i++) {
    ans2 += p * ((1 - qpow((1 - inv + mod) % mod, n) + mod) % mod) % mod;
    ans2 %= mod;
    inv *= inv26;
    inv %= mod;
    p *= 26;
    p %= mod;
  }
  std::cout << ans1 << ' ' << ans2 << '\n';
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