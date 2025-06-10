#include <bits/stdc++.h>
#define int long long

constexpr int mod = 1e9 + 7;

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
  int l, r, k;
  std::cin >> l >> r >> k;
  int c = 9 / k + 1;
  // std::cerr << c << '\n';
  auto calc = [&](int len) {
    if (len < 0) return 0ll;
    len++;
    return qpow(c, len);
  };
  int ans = (calc(r - 1) - calc(l - 1) + mod) % mod;
  if (l == 0) ans--;
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