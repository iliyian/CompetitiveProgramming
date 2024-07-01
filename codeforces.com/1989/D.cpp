// date: 2024-06-28 11:58:33
// tag: dp，贪心

#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  freopen("D.in", "r", stdin);
  freopen("D.out", "w", stdout);

  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  int mx = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    mx = max(mx, a[i]);
  }
  vector<int> mp(mx + 1, mx);
  for (int i = 0; i < n; i++) {
    int b;
    cin >> b;
    mp[a[i]] = min(mp[a[i]], a[i] - b);
  }
  for (int i = 1; i <= mx; i++) {
    mp[i] = min(mp[i], mp[i - 1]);
  }
  vector<int> f(mx + 1);
  for (int i = 0; i <= mx; i++) {
    if (i >= mp[i]) { // bound
      f[i] = max(f[i], f[i - mp[i]] + 1);
    }
  }
  int ans = 0;
  for (int i = 0; i < m; i++) {
    int c;
    cin >> c;
    if (c > mx) {
      int t = (c - mx - 1) / mp[mx] + 1;
      c -= t * mp[mx];
      ans += t;
    }
    ans += f[c];
  }
  cout << ans * 2 << '\n';

  return 0;
}