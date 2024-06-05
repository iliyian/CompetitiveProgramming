// date: 2024-06-05 21:59:12
// tag: 数学，组合数

#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int n, p;
  cin >> n >> p;

  vector<int> fac(n + 1), invfac(n + 1), inv(n + 1);
  fac[0] = fac[1] = invfac[0] = invfac[1] = inv[1] = 1;
  for (int i = 2; i <= n; i++) {
    fac[i] = i * fac[i - 1] % p;
    inv[i] = (p - p / i) * inv[p % i] % p;
  }
  for (int i = 2; i <= n; i++) {
    invfac[i] = inv[i] * invfac[i - 1] % p;
  }

  auto C = [&](int n, int m) {
    return fac[n] * invfac[n - m] % p * invfac[m] % p;
  };

  int ans = 0, ini = (n & 1 ? 2 : 1);
  for (int i = ini; i <= n / 2 + (n & 1); i++) { // [] distance
    if (i == 1) {
      ans += fac[n - 2];
      ans %= p;
      continue;
    }
    int tmp = 0;
    for (int j = 0; j <= i - 2; j++) {
      tmp += fac[n - j - 3] * C(i - 2, j) % p;
      tmp %= p;
    }
    tmp *= (n & 1 ? i - 1 : i);
    tmp %= p;
    ans += tmp;
    ans %= p;
  }
  ans = ans * n % p;
  cout << ans << '\n';

  return 0;
}