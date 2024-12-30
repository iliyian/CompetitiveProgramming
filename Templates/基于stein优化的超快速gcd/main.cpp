#include <bits/stdc++.h>
#define int long long

constexpr int mod = 998244353;

int gcd(int x, int y) {
  int xz = __builtin_ctzll(x), yz = __builtin_ctzll(y);
  int z = std::min(xz, yz);
  int dif;
  x >>= xz;
  while (y) {
    y >>= yz;
    dif = x - y;
    yz = __builtin_ctzll(dif);
    if (y < x) x = y;
    y = std::abs(dif);
  }
  return x << z;
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1), b(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    std::cin >> b[i];
  }
  gcd(3, 9);
  for (int i = 1; i <= n; i++) {
    int t = i, ans = 0;
    for (int j = 1; j <= n; j++) {
      ans += gcd(a[i], b[j]) * t % mod;
      ans %= mod;
      t *= i;
      t %= mod;
    }
    std::cout << ans << '\n';
  }
  return 0;
}