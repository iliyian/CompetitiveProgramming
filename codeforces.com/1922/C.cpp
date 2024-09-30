// date: 2024/01/29 13:00:48
// tag: 前缀和思想

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1), l(n + 1), r(n + 1);
  int pre = 0;
  l[1] = 0, l[2] = 1;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (i > 2) {
      l[i] = l[i - 1] + (a[i] - a[i - 1] > pre ? a[i] - a[i - 1] : 1);
    }
    pre = a[i] - a[i - 1];
  }
  pre = a[n] - a[n - 1];

  r[n] = 0, r[n - 1] = 1;
  for (int i = n - 2; i >= 1; i--) {
    r[i] = r[i + 1] + (a[i + 1] - a[i] > pre ? a[i + 1] - a[i] : 1);
    pre = a[i + 1] - a[i];
  }
  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int x, y;
    cin >> x >> y;
    cout << (x < y ? l[y] - l[x] : r[y] - r[x]) << '\n';
  }
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("C.in", "r", stdin);
  freopen("C.out", "w", stdout);
  int _; cin >> _;
  while (_--) solve();
}