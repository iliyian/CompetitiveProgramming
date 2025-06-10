#include <bits/stdc++.h>
#define int long long

constexpr int mod = 998244353;
constexpr int N = 5e5;
int inv[N + 1], fac[N + 1], invfac[N + 1];

int C(int n, int m) {
  if (n < m) return 0;
  if (m < 0) return 0;
  return fac[n] * invfac[m] % mod * invfac[n - m] % mod;
}

void solve() {
  int c[27] {}, s[27] {};
  int sum = 0;
  for (int i = 1; i <= 26; i++) {
    std::cin >> c[i];
    sum += c[i];
  }
  std::vector<int> f(sum / 2 + 1);
  f[0] = 1;
  for (int i = 1; i <= 26; i++) {
    if (!c[i]) continue;
    for (int j = sum / 2; j >= c[i]; j--) {
      f[j] += f[j - c[i]];
    }
  }
  // std::cerr << f[sum / 2] << '\n';
  int ans = f[sum / 2] * fac[sum / 2] % mod * fac[(sum + 1) / 2] % mod;
  for (int i = 1; i <= 26; i++) {
    if (c[i]) {
      ans *= invfac[c[i]];
      ans %= mod;
    }
  }
  std::cout << ans << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  inv[1] = fac[1] = invfac[1] = fac[0] = invfac[0] = 1;
  for (int i = 2; i <= N; i++) {
    inv[i] = (mod - mod / i) * inv[mod % i] % mod;
    fac[i] = fac[i - 1] * i % mod;
    invfac[i] = invfac[i - 1] * inv[i] % mod;
  }
  // std::cerr << C(132, 66) << '\n';

  int t = 1;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}