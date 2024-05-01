// date: 2024-05-01 16:51:10
// tag: 数学，模拟

#include <bits/stdc++.h>
#define int long long
#define mod ((int)1e9 + 7)
using namespace std;

void solve() {
  int b1, bd, bn, c1, cd, cn;
  cin >> b1 >> bd >> bn >> c1 >> cd >> cn;
  int br = b1 + (bn - 1) * bd, cr = c1 + (cn - 1) * cd;
  if (cd % bd || c1 < b1 || (c1 - b1) % bd || cr > br) {
      cout << 0 << '\n';
      return;
    }
  if (cr + cd > br || c1 - cd < b1) {
    cout << -1 << '\n';
    return;
  }
  int ans = 0;
  for (int i = 1; i * i <= cd; i++) {
    if (cd % i == 0) {
      if (lcm(bd, cd / i) == cd) {
        ans += i * i % mod;
        ans %= mod;
      }
      if (i * i != cd) {
        if (lcm(bd, i) == cd) {
          ans += (cd / i) * (cd / i) % mod;
          ans %= mod;
        }
      }
    }
  }
  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("D.in", "r", stdin);
  freopen("D.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}