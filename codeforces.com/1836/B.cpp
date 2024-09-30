#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n, k, g;
  cin >> n >> k >> g;
  int mx = (g % 2 ? g / 2 : g / 2 - 1);
  if (mx * n >= k * g) {
    cout << k * g << '\n';
    return;
  }
  int ans = mx * (n - 1);
  int last = k * g - ans;
  int r = last - last / g * g;
  if (r < ceil(g / 2.0)) ans += r;
  else ans -= g - r;
  cout << ans << '\n';
}
// 91 2 13
// 6 6 6 6 2
//
// 36 16 6
// 2 2 2 2 2 ... 26

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("B.in", "r", stdin);
  freopen("B.out", "w", stdout);
  int _; cin >> _;
  while (_--) solve();
}