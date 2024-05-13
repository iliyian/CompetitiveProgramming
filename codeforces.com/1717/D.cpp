// date: 2024-05-12 12:22:36
// tag: 构造。关键在于找不变量

#include <bits/stdc++.h>
#define int long long
#define mod ((int)1e9 + 7)
#define N ((int)1e5)
using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("D.in", "r", stdin);
  freopen("D.out", "w", stdout);

  int n, k;
  cin >> n >> k;

  auto qpow = [&](int a, int b) {
    int ans = 1;
    while (b) {
      if (b & 1) ans = ans * a % mod;
      a = a * a % mod;
      b >>= 1;
    }
    return ans;
  };

  vector<int> fac(n + 1), invfac(n + 1), inv(n + 1);
  fac[0] = fac[1] = inv[1] = invfac[0] = invfac[1] = 1;
  for (int i = 2; i <= n; i++) {
    fac[i] = fac[i - 1] * i % mod;
    inv[i] = (mod - mod / i) * inv[mod % i] % mod;
  }
  for (int i = 2; i <= n; i++) {
    invfac[i] = invfac[i - 1] * inv[i] % mod;
  }

  auto C = [&fac, &invfac](int n, int m) {
    int ans = fac[n] * invfac[m] % mod * invfac[n - m] % mod;
    return ans;
  };

  if (k >= n) {
    cout << qpow(2, n) << '\n';
    return 0;
  }

  int ans = 0;
  for (int i = 0; i <= k; i++) {
    ans += C(n, i);
    ans %= mod;
  }
  cout << ans << '\n';

  return 0;
}