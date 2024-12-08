#include <bits/stdc++.h>
#define int long long

constexpr int mod = 1e9 + 7;

int n, s;

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
  int ans = 1;
  std::cin >> n >> s;
  n %= mod;
  for (int i = 0; i <= s; i++) {
    ans = ans * (n + i) % mod;
  }
  std::cout << ans * qpow(s + 1, mod - 2) % mod << '\n';
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  // std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}