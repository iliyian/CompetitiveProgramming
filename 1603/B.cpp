// date: 2024-04-15 20:20:50
// tag: 构造

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int x, y;
  cin >> x >> y;
  int ans;
  if (y % x == 0) {
    ans = y;
  } else if (y < x) {
    ans = x + y;
  } else {
    ans = y - y % x / 2;
  }
  cout << ans << '\n';
  assert(ans % x == y % ans);
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("B.in", "r", stdin);
  freopen("B.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}