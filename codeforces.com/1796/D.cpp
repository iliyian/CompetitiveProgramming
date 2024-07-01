// date: 2024-06-23 20:56:30
// tag: 类似最大字段和的dp

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n, k, x;
  cin >> n >> k >> x;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    a[i] -= x;
  }
  vector<vector<int>> f(n + 1, vector<int>(k + 1));
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= k; j++) {
      if (j == 0) {
        f[i][0] = max(f[i - 1][0] + a[i], 0ll);
      } else if (i < j) {
        f[i][j] = 0;
      } else if (i == j) {
        f[i][j] = max(f[i - 1][j - 1] + a[i] + 2 * x, 0ll);
      } else {
        f[i][j] = max({f[i - 1][j - 1] + a[i] + 2 * x, f[i - 1][j] + a[i], 0ll});
      }
      if (k - j <= n - i) { // capability
        ans = max(ans, f[i][j]);
        // cout << i << ' ' << j << '\n';
      }
    }
  }
  cout << ans << '\n';
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