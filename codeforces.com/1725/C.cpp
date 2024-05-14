// date: 2024-05-13 13:10:08
// tag: 数学，排列组合

#include <algorithm>
#include <bits/stdc++.h>
#define int long long
#define N ((int)3e5)
#define mod 998244353
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
  return fac[n] * invfac[n - m] % mod * invfac[m] % mod;
}

int A(int n, int m) {
  return fac[n] * invfac[n - m] % mod;
}

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    a[i] += a[i - 1];
  }
  int k = 0;
  if (a[n] & 1 ^ 1) {
    int hal = a[n] / 2;
    for (int i = 1; i <= n; i++) {
      auto pos = lower_bound(a.begin() + 1, a.end(), a[i] - hal);
      if (pos != a.end() && *pos == a[i] - hal) {
        k++;
      }
    }
  }
  int ans = 0;
  for (int i = 0; i <= min(k, m); i++) {
    ans += C(k, i) * A(m, i) % mod
      * qpow(m - i - 1, k - i) % mod
      * qpow(m - i, k - i) % mod
      * qpow(m - i, n - 2 * k) % mod;
    ans %= mod;
  }
  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("C.in", "r", stdin);
  freopen("C.out", "w", stdout);

  fac[0] = fac[1] = inv[1] = invfac[0] = 1;
  for (int i = 2; i <= N; i++) {
    fac[i] = fac[i - 1] * i % mod;
    inv[i] = (mod - mod / i) * inv[mod % i] % mod;
  }
  for (int i = 1; i <= N; i++) {
    invfac[i] = invfac[i - 1] * inv[i] % mod;
  }

  solve();

  return 0;
}