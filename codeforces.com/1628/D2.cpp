// date: 2024-05-19 20:59:21
// tag: 组合数

#include <bits/stdc++.h>
#define int long long
#define mod ((int)1e9 + 7)
#define N ((int)1e6)
using namespace std;

vector<int> inv(N + 1), fac(N + 1), invfac(N + 1);

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
  return fac[n] * invfac[m] % mod * invfac[n - m] % mod;
}

void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  if (n == m) {
    cout << m * k % mod << '\n';
    return;
  }
  int ans = 0;
  for (int i = 1; i <= m; i++) {
    ans += i * k % mod * C(n - i - 1, m - i) % mod * qpow(inv[2], n - i) % mod;
    ans %= mod;
  }
  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("D2.in", "r", stdin);
  freopen("D2.out", "w", stdout);

  inv[1] = fac[0] = fac[1] = invfac[1] = invfac[0] = 1;
  for (int i = 2; i <= N; i++) {
    inv[i] = (mod - mod / i) * inv[mod % i] % mod;
    fac[i] = fac[i - 1] * i % mod;
  }
  for (int i = 2; i <= N; i++) {
    invfac[i] = invfac[i - 1] * inv[i] % mod;
  }

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}