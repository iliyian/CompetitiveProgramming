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

int inv(int x) {
  return qpow(x, mod - 2);
}

void solve() {
  int n;
  std::cin >> n;
  if (n == 1) {
    std::cout << 0 << '\n';
  } else {
    int t = n / 2;
    int r = (n % 2 == 0 ? n : n - 1);
    int ans = (2 + r) * t % mod * inv(2) % mod;
    std::cout << ans << '\n';
  }
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