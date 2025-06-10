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
  int n, w, x, y;
  std::cin >> n >> w >> x >> y;
  if (x * 2 == y) {
    std::cout << n * qpow(2, mod - 2) % mod << '\n';
  } else if (x * 2 > y) {
    std::cout << 1 << '\n';
  } else {
    std::cout << 0 << '\n';
  }
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