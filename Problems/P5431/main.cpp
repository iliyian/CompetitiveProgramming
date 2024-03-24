// date: 2024-03-24 16:19:54
// tag: 乘法逆元，前后缀积

#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  int n, p, k;
  cin >> n >> p >> k;
  vector<int> a(n + 1), l(n + 2), r(n + 2);
  int s = 1;
  l[0] = r[n + 1] = 1;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    l[i] = a[i] * l[i - 1] % p;
  }
  for (int i = n; i >= 1; i--) {
    r[i] = a[i] * r[i + 1] % p;
  }
  auto exgcd = [&](auto self, int a, int b, int &x, int &y) {
    if (b == 0) {
      x = 1, y = 0;
      return;
    }
    self(self, b, a % b, y, x);
    y -= a / b * x;
  };
  int ans = 0;
  for (int i = n; i >= 1; i--) {
    // 巧妙的化除为积
    ans = (ans + l[i - 1] * r[i + 1] % p) * k % p;
    assert(ans >= 0);
  }
  int x, y;
  exgcd(exgcd, r[1], p, x, y);
  x = (x % p + p) % p;
  cout << ans * x % p << '\n';

  return 0;
}