#include <bits/stdc++.h>
#define int long long

constexpr int N = 1e5, mod = 998244353;
std::vector<int> primes, minp;

std::vector<int> fac, invfac, inv;
std::vector<std::vector<int>> f, factors, g;

int C(int n, int m) {
  if (n < 0 || m < 0) return 0;
  if (n < m) return 0;
  return fac[n] * invfac[n - m] % mod * invfac[m] % mod;
}

void solve() {
  int n, m;
  std::cin >> m >> n;
  int ans = C(m, n) * n % mod;
  for (int g = 1; g <= m; g++) {
    int r = m / g - 1;
    for (int l = 1; l <= std::min<int>(n, 20); l++) {
      ans -= f[g][l] * C(r, n - l) % mod;
      ans = (ans + mod) % mod;
    }
  }
  std::cout << ans << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  minp.assign(N + 1, 0);
  fac.assign(N + 1, 0);
  invfac.assign(N + 1, 0);
  inv.assign(N + 1, 0);
  f.assign(N + 1, std::vector<int>(21));
  factors.assign(N + 1, std::vector<int>());
  invfac[1] = fac[1] = inv[1] = fac[0] = invfac[0] = 1;

  for (int i = 2; i <= N; i++) {
    fac[i] = fac[i - 1] * i % mod;
    inv[i] = (mod - mod / i) * inv[mod % i] % mod;
    invfac[i] = invfac[i - 1] * inv[i] % mod;
  }
  for (int i = 1; i <= N; i++) {
    for (int j = i; j <= N; j += i) {
      factors[j].push_back(i);
    }
  }

  f[1][1] = 1;
  for (int i = 2; i <= N; i++) {
    f[i][1] = 1;
    for (int d : factors[i]) {
      if (d != i) {
        for (int j = 2; j <= 20; j++) {
          f[i][j] += f[d][j - 1];
          f[i][j] %= mod;
        }
      }
    }
  }

  int t = 1;
  // std::cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}