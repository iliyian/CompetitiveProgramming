// date: 2024-03-20 21:33:27
// tag: 排列组合，概率
// wa#01: 边界的特判出错
// wa#02: 2的幂的逆元即可而非2的逆元的幂
// re#03: 1e6写成1e5

#include <bits/stdc++.h>
#define int long long
#define mod 998244353
using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("F.in", "r", stdin);
  freopen("F.out", "w", stdout);

  int n, q;
  cin >> n >> q;
  vector<int> a(n + 1), b(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    a[i] += a[i - 1];
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
    b[i] += b[i - 1];
  }
  vector<int> C(1000001), inv(b[n] + 1);
  inv[1] = 1;
  for (int i = 2; i <= b[n]; i++) {
    inv[i] = (mod - mod / i) * inv[mod % i] % mod;
  }
  C[0] = 1;
  for (int i = 1; i <= b[n]; i++) {
    C[i] = C[i - 1] * (b[n] - i + 1) % mod * inv[i] % mod;
  }
  for (int i = 1; i <= b[n]; i++) {
    C[i] = (C[i - 1] + C[i]) % mod;
  }
  auto exgcd = [](auto self, int a, int b, int &x, int &y) -> void {
    if (b == 0) {
      x = 1, y = 0;
      return;
    }
    self(self, b, a % b, y, x);
    y -= a / b * x;
  };
  auto qpow = [](int a, int b, int p) {
    int ans = 1;
    while (b) {
      if (b & 1) ans = ans * a % p;
      a = a * a % p;
      b >>= 1;
    }
    return ans;
  };
  int x, y;
  int p = qpow(2, b[n], mod);
  exgcd(exgcd, p, mod, x, y);
  x = (x % mod + mod) % mod;

  for (int t = 0; t < q; t++) {
    int l, r;
    cin >> l >> r;
    int ain = a[r] - a[l - 1], aout = a[n] - a[r] + a[l - 1];
    int bin = b[r] - b[l - 1], bout = b[n] - b[r] + b[l - 1];
    // for (int i = aout - ain + 1,)
    // [aout-ain+1, bin]
    int k = bin - (aout - ain) - 1;
    k = min(k, b[n]);
    if (k < 0) {
      cout << 0 << ' ';
      continue;
    }
    int ans = C[k];
    // int ans
    ans = ans * x % mod;
    cout << ans << ' ';
  }

  return 0;
}