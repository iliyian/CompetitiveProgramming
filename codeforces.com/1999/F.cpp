#include <bits/stdc++.h>
#define int long long
// using namespace std;

constexpr int N = 2e5;
constexpr int mod = 1e9 + 7;

std::vector<int> fac(N + 1), invfac(N + 1), inv(N + 1);

int C(int n, int m) {
  if (n == 0 || m == 0 || n == m) return 1;
  return fac[n] * invfac[m] % mod * invfac[n - m] % mod;
}

void solve() {
  int n, k;
  std::cin >> n >> k;
  std::vector<int> a(n + 1);
  int cnt1 = 0;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    cnt1 += (a[i] == 1);
  }
  int ans = 0;
  for (int i = std::max(k - n + cnt1, (k + 1) / 2); i <= std::min(cnt1, k); i++) {
    ans += C(cnt1, i) * C(n - cnt1, k - i) % mod;
    ans %= mod;
  }
  std::cout << ans << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("F.in", "r", stdin);
  freopen("F.out", "w", stdout);

  inv[1] = fac[0] = fac[1] = invfac[0] = invfac[1] = 1;
  for (int i = 2; i <= N; i++) {
    inv[i] = (mod - mod / i) % mod * inv[mod % i] % mod;
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