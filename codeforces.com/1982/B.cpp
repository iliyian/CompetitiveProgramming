#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int x, y, k;
  cin >> x >> y >> k;

  while (k > 0) {
    if (x == 1) {
      cout << (k % (y - 1)) + 1 << '\n';
      return;
    }
    int t = ((x - 1) / y + 1) * y;
    if (x % y == 0) t += y;
    if (x + k < t) {
      cout << x + k << '\n';
      return;
    }
    k -= t - x;
    x = t;
    while (x % y == 0) x /= y;
  }
  cout << x << '\n';
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  freopen("B.in", "r", stdin);
  freopen("B.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}