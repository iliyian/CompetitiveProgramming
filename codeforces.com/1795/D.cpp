// date: 2024-06-23 16:46:33
// tag: 组合数

#include <bits/stdc++.h>
#define int long long
#define mod 998244353
#define N ((int)3e5)
using namespace std;

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  freopen("D.in", "r", stdin);
  freopen("D.out", "w", stdout);

  int n;
  cin >> n;

  vector<int> inv(n + 1), fac(n + 1), invfac(n + 1);
  inv[1] = fac[1] = fac[0] = invfac[1] = 1;
  for (int i = 2; i <= n; i++) {
    fac[i] = fac[i - 1] * i % mod;
    inv[i] = (mod - mod / i) * inv[mod % i] % mod;
  }
  for (int i = 2; i <= n; i++) {
    invfac[i] = invfac[i - 1] * inv[i] % mod;
  }
  
  int ans = fac[n / 3] * invfac[n / 6] % mod * invfac[n / 6] % mod;
  for (int i = 1; i <= n / 3; i++) {
    array<int, 4> a;
    for (int j = 1; j <= 3; j++) {
      cin >> a[j];
    }
    sort(a.begin() + 1, a.end());
    if (a[1] == a[2] && a[2] == a[3]) {
      ans = ans * 3 % mod;
    } else if (a[1] == a[2] && a[1] < a[3]) {
      ans = ans * 2 % mod;
    }
  }
  cout << ans << '\n';

  return 0;
}