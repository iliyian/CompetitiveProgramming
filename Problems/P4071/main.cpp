// date: 2024-03-06 21:06:32
// tag: TLE#01, #02, 组合数没有预处理

#include <bits/stdc++.h>
#define int long long
#define mod 1000000007
using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  int _;
  cin >> _;

  // for (int i = 1; i <= 7; i++) {
  //   vector<int> a(i);
  //   iota(a.begin(), a.end(), 1);
  //   int cnt = 0;
  //   do {
  //     bool f = true;
  //     for (int j = 0; j < i; j++) {
  //       if (j + 1 == a[j]) {
  //         f = false;
  //         break;
  //       }
  //     }
  //     if (f) {
  //       cnt++;
  //     }
  //   } while (next_permutation(a.begin(), a.end()));
  //   cout << cnt << '\n';
  // }

  vector<int> phi(1000005), inv(1000005), f(1000005);
  phi[0] = 1;
  phi[1] = 0;
  inv[1] = 1;
  f[0] = f[1] = 1;
  for (int i = 2; i <= 1000000; i++) {
    phi[i] = (i - 1) * ((phi[i - 1] + phi[i - 2]) % mod) % mod;
    inv[i] = (mod - mod / i) * inv[mod % i] % mod;
    f[i] = f[i - 1] * i % mod;
  }

  auto exgcd = [](auto self, int a, int b, int &x, int &y) -> void {
    if (b == 0) {
      x = 1, y = 0;
      return;
    }
    self(self, b, a % b, y, x);
    y -= a / b * x;
  };

  while (_--) {
    int n, m;
    cin >> n >> m;
    int ans = phi[n - m], t = f[m] * f[n - m] % mod;
    int iv, y;
    exgcd(exgcd, t, mod, iv, y);
    iv = (iv % mod + mod) % mod;
    ans = ans * f[n] % mod * iv % mod;
    cout << ans << '\n';
  }

  return 0;
}