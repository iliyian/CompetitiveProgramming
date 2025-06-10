#include <bits/stdc++.h>
#define int long long

constexpr int mod = 998244353;
constexpr int N = 200;
int fac[N + 1], inv[N + 1], invfac[N + 1];

// int C(int n, int m) {
//   return fac[n] * invfac[m] % mod * invfac[n - m] % mod;
// }

int qpow(int a, int b) {
  int ans = 1;
  while (b) {
    if (b & 1) ans = ans * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return ans;
}

int C(int n, int m) {
  if (m == 0) return 1;
  m = std::min(m, n - m);
  int ans = 1;
  for (int i = n; i >= n - m + 1; i--) {
    ans *= i;
    ans %= mod;
  }
  for (int i = 2; i <= m; i++) {
    ans *= inv[i];
    ans %= mod;
  }
  // ans *= invfac[m];
  // ans %= mod;
  return ans;
}

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<int> cnt(m + 1, n / m);
  int r = n % m, t = n / m;
  for (int i = 1; i <= r; i++) {
    cnt[i]++;
  }
  std::vector<std::vector<std::vector<int>>> f(m + 1, std::vector<std::vector<int>>(m + 1, std::vector<int>(t + 1 + 1)));
  std::vector<std::vector<int>> s(m + 1, std::vector<int>(m + 1));
  auto sub = [&](int x, int y) {
    x %= m, y %= m;
    int ans = x - y;
    if (!ans) return m;
    if (ans < 0) return ans + m;
    return ans;
  };
  s[0][m] = 1;
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= m; j++) {
      for (int k = 0; k <= cnt[i]; k++) {
        f[i][j][k] += s[i - 1][sub(j, i * k)] * C(cnt[i], k) % mod;
        f[i][j][k] %= mod;
        s[i][j] += f[i][j][k];
        s[i][j] %= mod;
      }
    }
  }
  int ans = s[m][m] - 1 + mod;
  ans %= mod;
  std::cout << ans << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  fac[0] = invfac[0] = inv[1] = fac[1] = invfac[1] = 1;
  for (int i = 2; i <= N; i++) {
    inv[i] = (mod - mod / i) * inv[mod % i] % mod;
    fac[i] = fac[i - 1] * i % mod;
    invfac[i] = invfac[i - 1] * inv[i] % mod;
  }

  int t = 1;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}