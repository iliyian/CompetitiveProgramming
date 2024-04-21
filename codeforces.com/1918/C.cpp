#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int a, b, r;
  cin >> a >> b >> r;
  if (a < b) swap(a, b);
  int ans = 0;
  for (int i = (1ll << 62ll); i >= 1; i >>= 1ll) {
    if ((i & a) == (i & b)) continue;
    if (i <= r) {
      if ((i & a) && ans > 0) {
        ans -= i;
        r -= i;
      } else if ((i & b) && ans < 0) {
        ans += i;
        r -= i;
      } else {
        ans += (i & a) ? i : -i;
      }
    } else {
      ans += (i & a) ? i : -i;
    }
  }
  cout << abs(ans) << '\n';
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("C.in", "r", stdin);
  freopen("C.out", "w", stdout);
  int _; cin >> _;
  while (_--) solve();
}