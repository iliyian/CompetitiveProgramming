// date: 2024-06-04 11:26:56
// tag: 分类讨论，模拟

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  int mx = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    mx = max(mx, a[i]);
  }
  if (n == 2) {
    cout << max({a[0] + a[1], 2 * abs(a[0] - a[1])}) << '\n';
  } else if (n > 3) {
    cout << mx * n << '\n';
  } else {
    if (a[1] == mx) {
      cout << max({3 * a[0], 3 * a[2],
        a[0] + 2 * abs(a[1] - a[2]), a[2] + 2 * abs(a[0] - a[1]),
        3 * abs(a[0] - a[1]), 3 * abs(a[1] - a[2]),
        a[0] + a[1] + a[2]}) << '\n';
    } else {
      cout << mx * 3 << '\n';
    }
  }
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  freopen("C.in", "r", stdin);
  freopen("C.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}