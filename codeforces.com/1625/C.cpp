// date: 2024-04-22 17:22:37
// tag: dp

#include <bits/stdc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("C.in", "r", stdin);
  freopen("C.out", "w", stdout);

  int n, l, maxk;
  cin >> n >> l >> maxk;
  vector<int> d(n + 2), a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> d[i];
  }
  d[n + 1] = l;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  vector<vector<int>> f(n + 2, vector<int>(maxk + 1, inf));
  f[1][0] = 0;
  for (int i = 2; i <= n + 1; i++) {
    for (int k = 0; k <= min(maxk, i - 2); k++) {
      for (int c = 0; c <= k; c++) {
        f[i][k] = min(f[i][k],
          f[i - c - 1][k - c] + (d[i] - d[i - c - 1]) * a[i - c - 1]);
      }
    }
  }
  int ans = inf;
  for (int k = 0; k <= maxk; k++) {
    ans = min(ans, f[n + 1][k]);
  }
  cout << ans << '\n';

  return 0;
}