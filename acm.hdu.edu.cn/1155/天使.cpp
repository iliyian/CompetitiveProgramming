#include <bits/stdc++.h>
#define int long long

constexpr int N = 2e5;
constexpr int mod = 1e9 + 7;
int fac[N + 1], invfac[N + 1], inv[N + 1], f[N + 1];

int C(int n, int m) {
  return fac[n] * invfac[n - m] % mod * invfac[m] % mod;
}

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    ans += a[i] * a[i - 1] % mod;
    ans %= mod;
    a[i] += a[i - 1];
    a[i] %= mod;
  }
  std::cout << ans << ' ' << f[n] << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  fac[0] = fac[1] = invfac[0] = invfac[1] = inv[1] = 1;
  for (int i = 2; i <= N; i++) {
    fac[i] = fac[i - 1] * i % mod;
    inv[i] = (mod - mod / i) * inv[mod % i] % mod;
    invfac[i] = invfac[i - 1] * inv[i] % mod;
  }
  f[1] = 1;
  f[2] = 1;
  for (int i = 3; i <= N; i++) {
    // f[i] = f[i - 1] * (2 * i - 3) % mod;
    f[i] = f[i - 1] * i % mod * (i - 1) % mod * inv[2] % mod;
    // std::cerr << f[i] << ' ';
  }
  // std::cerr << '\n';
  // // 3 15 105 945 10395 135135 2027025 34459425 654729075 2749310498 3234141034 2853525304 4045182697 4310297422 4619219179 4434231871 4198114428 7330232800 
  // for (int i = 3; i <= N; i++) {
  //   // f[i] += C(i, 1) * f[1] % mod * f[i - 1] % mod;
  //   // f[i] %= mod;
  //   for (int j = 1; j <= i - 2; j++) {
  //     f[i] += C(i, j) * f[j] % mod * f[i - j] % mod;
  //     f[i] %= mod;
  //   }
  //   // g[i] = g[i - 1] + f[i];
    // std::cerr << f[i] << ' ';
  //   // std::cerr << f[i] << ' ' << g[i] << '\n';
  // }

  int t = 1;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}