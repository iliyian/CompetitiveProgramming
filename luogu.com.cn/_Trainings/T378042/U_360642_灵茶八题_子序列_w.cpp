#include <bits/stdc++.h>
#define int long long

constexpr int mod = 1e9 + 7;

int qpow(int a, int b) {
  int ans = 1;
  while (b) {
    if (b & 1) ans = ans * a % mod;
    a = a * a % mod;
    b /= 2;
  }
  return ans;
}

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  int ans = 0;
  for (int i = 30; i >= 0; i--) {
    int c1 = 0, c0 = 0;
    for (int j = 1; j <= n; j++) {
      if (a[j] >> i & 1) c1++;
      else c0++;
    }
    if (c1) {
      ans += qpow(2, c0 + c1 - 1) * qpow(2, i) % mod;
      ans %= mod;
    }
    // std::cerr << ans << ' ';
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