// date: 2024-05-07 15:55:07
// tag: 组合数结论

#include <bits/stdc++.h>
#define int long long
#define mod ((int)1e9 + 7)
#define N 200000
using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("E.in", "r", stdin);
  freopen("E.out", "w", stdout);

  int n;
  cin >> n;
  vector<int> a(n + 1), fac(N * 2 + 1);
  fac[0] = fac[1] = 1;
  for (int i = 2; i <= N * 2; i++) {
    fac[i] = fac[i - 1] * i % mod;
  }
  for (int i = 0; i <= n; i++) {
    cin >> a[i];
  }
  auto exgcd = [&](auto self, int a, int b, int &x, int &y) {
    if (b == 0) {
      x = 1, y = 0;
      return;
    }
    self(self, b, a % b, y, x);
    y -= a / b * x;
  };
  auto C = [&](int n, int m) {
    int ans = fac[n], x, y;
    exgcd(exgcd, fac[m], mod, x, y);
    x = (x % mod + mod) % mod;
    ans = ans * x % mod;

    exgcd(exgcd, fac[n - m], mod, x, y);
    x = (x % mod + mod) % mod;
    ans = ans * x % mod;

    return ans;
  };
  int ans = 0;
  for (int i = 0; i <= n; i++) {
    if (!a[i]) break;
    int r = i + 1, c = a[i] - 1;
    ans += C(r + c, r);
    ans %= mod;
  }
  cout << ans << '\n';

  return 0;
}