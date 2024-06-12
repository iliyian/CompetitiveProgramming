// date: 2024-06-08 16:57:41
// tag: 数学结论

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  double xmin = 0, xmax = 1e9;
  for (int i = 1; i <= n - 1; i++) {
    if (a[i] == a[i + 1]) continue;
    else if (a[i] > a[i + 1]) {
      xmin = max(xmin, (a[i] + a[i + 1]) / 2.0);
    } else {
      xmax = min(xmax, (a[i] + a[i + 1]) / 2.0);
    }
  }
  if (ceil(xmin) <= floor(xmax)) {
    cout << (int)(ceil(xmin)) << '\n';
    // for (int i = 1; i <= n; i++) {
    //   cout << abs(a[i] - (int)(ceil(xmin))) << ' ';
    // }
    // cout << '\n';
  } else {
    cout << -1 << '\n';
  }
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  freopen("D.in", "r", stdin);
  freopen("D.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}