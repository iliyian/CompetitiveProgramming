// date: 2024-04-18 14:58:57
// tag: 位运算，组合

#include <bits/stdc++.h>
#define int long long
#define mod 1000000007
using namespace std;

void solve() {
  int n, m;
  cin >> n >> m;
  int t = 0;
  for (int i = 1; i <= m; i++) {
    int l, r, x;
    cin >> l >> r >> x;
    t |= x;
  }
  int ans = 0;
  auto qpow = [&](int x, int y) {
    int ans = 1;
    while (y) {
      if (y & 1) ans = ans * x % mod;
      x = x * x % mod;
      y >>= 1;
    }
    return ans;
  };
  for (int i = 0; i < 31; i++) {
    if (t >> i & 1) {
      ans += qpow(2, i + n - 1);
      ans %= mod;
    }
  }
  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("C.in", "r", stdin);
  freopen("C.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}