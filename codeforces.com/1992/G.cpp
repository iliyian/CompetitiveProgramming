// date: 2024-08-10 15:46:06
// tag: 组合数

#include <bits/stdc++.h>
#define int long long
// using namespace std;

constexpr int mod = 1e9 + 7;
constexpr int N = 5000;

std::vector<int> fac(N + 1), inv(N + 1), invfac(N + 1);

int C(int n, int m) {
  if (n < m) return 0;
  if (n == 0 || m == 0) return 1;
  return fac[n] * invfac[m] % mod * invfac[n - m] % mod;
}

void solve() {
  int n;
  std::cin >> n;
  int ans = 0;
  for (int len = 0; len <= n; len++) {
    for (int x = len + 1; x <= len * 2 + 1; x++) {
      ans += x * C(std::min(n, x - 1), x - len - 1) % mod * C(std::max(0ll, n - x), len * 2 + 1 - x) % mod;
      ans %= mod;
    }
  }
  std::cout << ans << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("G.in", "r", stdin);
  freopen("G.out", "w", stdout);

  inv[1] = fac[0] = fac[1] = invfac[0] = invfac[1] = 1;
  for (int i = 2; i <= N; i++) {
    inv[i] = (mod - mod / i) * inv[mod % i] % mod;
    fac[i] = fac[i - 1] * i % mod;
    invfac[i] = invfac[i - 1] * inv[i] % mod;
  }

  int _;
  std::cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}