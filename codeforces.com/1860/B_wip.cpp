#include <bits/stdc++.h>
#define int long long
using namespace std;

int m, k, a1, ak;

void solve() {
  cin >> m >> k >> a1 >> ak;
  int taken_1 = m % k, taken_k = m / k;
  int taken_fancy_1 = max(0ll, taken_1 - a1),
    taken_fancy_k = max(0ll, taken_k - ak);
  
  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("B.in", "r", stdin);
  freopen("B.out", "w", stdout);
  int _; cin >> _;
  while (_--) solve();
}