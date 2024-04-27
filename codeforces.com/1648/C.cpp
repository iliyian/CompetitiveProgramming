// date: 2024-04-25 17:44:25
// tag: 数学

#include <bits/stdc++.h>
#define int long long
#define mod 998244353
#define N 200000
using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("C.in", "r", stdin);
  freopen("C.out", "w", stdout);

  int n, m;
  cin >> n >> m;
  vector<int> a(n + 1), b(m + 1), d(N + 1), cnt(N + 1);

  auto add = [&](int x, int c) {
    for (int i = x; i <= N; i += i & -i) {
      d[i] += c;
    }
  };

  auto sum = [&](int x) {
    int ans = 0;
    for (int i = x; i > 0; i -= i & -i) {
      ans += d[i];
    }
    return ans;
  };
  
  auto exgcd = [](auto self, int a, int b, int &x, int &y) -> void {
    if (b == 0) {
      x = 1, y = 0;
      return;
    }
    self(self, b, a % b, y, x);
    y -= a / b * x;
  };

  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    add(a[i], 1);
    cnt[a[i]]++;
  }
  for (int i = 1; i <= m; i++) {
    cin >> b[i];
  }

  vector<int> fac(N + 1), inv(N + 1);
  fac[0] = fac[1] = inv[1] = 1;
  for (int i = 2; i <= N; i++) {
    fac[i] = fac[i - 1] * i % mod;
    inv[i] = (mod - mod / i) * inv[mod % i] % mod;
  }

  int facmul = 1;
  for (int i = 1; i <= N; i++) {
    facmul = facmul * fac[cnt[i]] % mod;
  }
  int x, y;
  exgcd(exgcd, facmul, mod, x, y);
  facmul = (x % mod + mod) % mod;

  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (i > m) {
      break;
    }

    ans += fac[n - i] * sum(b[i] - 1) % mod * facmul % mod;
    ans %= mod;
    int bcnt = sum(b[i]) - sum(b[i] - 1);
    if (bcnt) {
      facmul = facmul * bcnt % mod;
      add(b[i], -1);
    } else break; // 失配
  }
  if (!sum(N) && m > n) ans = (ans + 1) % mod;

  cout << ans << '\n';

  return 0;
}