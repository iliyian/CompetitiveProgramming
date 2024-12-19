#include <bits/stdc++.h>
#define int long long

constexpr int mod = 998244353;

int gcd(int x, int y) {
  if (x == 0) return y;
  if (y == 0) return x;
  // std::cout << x << ' ' << y << '\n';
  int c = std::min(__builtin_ctzll(x), __builtin_ctzll(y));
  x >>= c, y >>= c;
  while (y) {
    auto d = x - y;
    d = std::abs(d);
    d >>= __builtin_ctzll(d);
    if (y < x) x = d;
    else y = d;
  }
  return x << c;
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
  // gcd(48,30);
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