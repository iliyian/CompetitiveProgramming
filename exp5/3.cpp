#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n, a, b;
  cin >> n >> a >> b;
  int m = min(a, b);

  if (a / 2.0 < b / 3.0) {
    if (n % 2) cout << min((n / 2 - 1) * a + b, n / 2 * a + m) << '\n';
    else cout << n / 2 * a << '\n';
  } else {
    if (n % 3 == 1) cout << min((n / 3 - 1) * b + 2 * a, n / 3 * b + m) << '\n';
    else if (n % 3 == 2) cout << n / 3 * b + m << '\n';
    else cout << n / 3 * b << '\n';
  }

}

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("3.in", "r", stdin);
  freopen("3.out", "w", stdout);
  int _; cin >> _;
  while (_--) solve();
}