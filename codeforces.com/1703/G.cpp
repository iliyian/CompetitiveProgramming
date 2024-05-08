// date: 2024-05-08 16:24:29
// tag: dp，贪心

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n + 1);
  vector<vector<int>> f(n + 1, vector<int>(32));
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  f[1][0] = a[1] - k;
  f[1][1] = a[1] / 2;
  for (int i = 2; i <= n; i++) {
    f[i][0] = f[i - 1][0] - k + a[i];
    int lim = min(30ll, i);
    f[i][lim] = f[i - 1][lim - 1] + (a[i] >> lim);
    for (int j = 1; j < lim; j++) {
      f[i][j] = max(f[i - 1][j] - k + (a[i] >> j), f[i - 1][j - 1] + (a[i] >> j));
    }
    if (i > 30) {
      f[i][31] = max(f[i - 1][30], f[i - 1][31]);
    }
  }
  int ans = LLONG_MIN;
  for (int i = 0; i <= min(31ll, n); i++) {
    ans = max(ans, f[n][i]);
  }
  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("G.in", "r", stdin);
  freopen("G.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}