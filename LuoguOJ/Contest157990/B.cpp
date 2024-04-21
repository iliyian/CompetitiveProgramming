#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  double a, b, c, d, e, x, y;
  cin >> a >> b >> c >> d >> e >> x >> y;
  double ans1 = a * x + b * y;
  double ans2 = c * y;
  double ans3 = d * y + e;
  if (ans1 >= ans2 && ans1 >= ans3) {
    cout << 1 << ' ' << fixed << setprecision(2) << ans1 << '\n';
  } else if (ans2 >= ans1 && ans2 >= ans3) {
    cout << 2 << ' ' << fixed << setprecision(2) << ans2 << '\n';
  } else if (ans3 >= ans1 && ans3 >= ans2) {
    cout << 3 << ' ' << fixed << setprecision(2) << ans3 << '\n';
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("B.in", "r", stdin);
  freopen("B.out", "w", stdout);

  int t = 1;

  while (t--) {
    solve();
  }

  return 0;
}