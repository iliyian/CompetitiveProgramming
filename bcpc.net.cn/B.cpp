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

int inv(int x) {
  return qpow(x, mod - 2);
}

int calc(int l, int r) {
  return (l + r) % mod * (r - l + 1 + mod) % mod * inv(2) % mod;
}

void solve() {
  int x, y;
  std::cin >> x >> y;
  std::vector<int> a;
  int t = 1;
  for (int i = 1; i <= x; i++) {
    a.push_back(t * 5 % mod);
    t *= 10;
    t %= mod;
  }
  std::reverse(a.begin(), a.end());
  int l = 5 * qpow(10, x - 1) % mod;
  y = std::min(y, x);
  int ans = 0;
  for (int i = 0; i < y; i++) {
    int r = l + a[i] - 1;
    // std::cout << l << ' ' << r << '\n';
    r %= mod;
    ans += calc(l, r);
    ans %= mod;
    if (i < y - 1) {
      l = (l - a[i + 1]) % mod;
      l = (l + mod) % mod;
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