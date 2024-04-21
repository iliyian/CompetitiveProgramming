// date: 2024-04-08 22:36:52
// tag: 状压dp

#include <bits/stdc++.h>
#define int long long
#define mod 100000000
using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  int m, n;
  cin >> m >> n;
  vector<vector<int>> a(m, vector<int>(n));
  vector<vector<bool>> ok(m, vector<bool>(1 << n));
  for (int i = 0; i < m; i++) {
    int bad = 0;
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
      if (a[i][j] == 0) {
        bad |= 1 << j;
      }
    }
    for (int S = (1 << n) - 1; S >= 0; S--) {
      ok[i][S] = !(S & bad) && !(S & (S << 1));
    }
  }
  vector<vector<int>> f(m, vector<int>(1 << n));
  for (int S = (1 << n) - 1; S >= 0; S--) {
    f[0][S] = ok[0][S];
  }
  for (int i = 1; i < m; i++) {
    for (int S = (1 << n) - 1; S >= 0; S--) {
      if (!ok[i][S]) continue;
      for (int prv = (1 << n) - 1; prv >= 0; prv--) {
        if (!ok[i - 1][prv] || S & prv) continue;
        f[i][S] = (f[i][S] + f[i - 1][prv]) % mod;
      }
    }
  }
  int ans = 0;
  for (int S = (1 << n) - 1; S >= 0; S--) {
    ans = (ans + f[m - 1][S]) % mod;
  }
  cout << ans << '\n';

  return 0;
}