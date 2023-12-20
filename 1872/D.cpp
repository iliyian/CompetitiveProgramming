#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n, x, y;
  cin >> n >> x >> y;
  int z = x * y / gcd(x, y);
  int cntx = n / x - n / z;
  int cnty = n / y - n / z;
  int ans = (n + (n - cntx + 1)) * cntx / 2 - (1 + cnty) * cnty / 2;
  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("D.in", "r", stdin);
  freopen("D.out", "w", stdout);
  int _; cin >> _;
  while (_--) solve();
}