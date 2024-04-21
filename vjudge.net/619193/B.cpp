// date: 2024-03-28 22:21:55
// tag: 

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1);
  int mx1 = 0, mx2 = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    a[i] += a[i - 1];
    if (a[i] < 0) mx1 = max(mx1, -a[i]);
    if (a[i] > 0) mx2 = max(mx2, a[i]);
  }
  cout << mx1 + mx2 << '\n';
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