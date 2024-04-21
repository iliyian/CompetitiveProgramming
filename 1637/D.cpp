// date: 2024-04-07 12:53:53
// tag: 动态规划，数学

#include <bits/stdc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1), b(n + 1), s(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
  }
  for (int i = 1; i <= n; i++) {
    s[i] = s[i - 1] + a[i] + b[i];
  }
  vector<vector<int>> f(n + 1, vector<int>(s[n] + 1, inf));
  f[0][0] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= s[i]; j++) {
      if (j >= a[i]) {
        f[i][j] = min(f[i][j],
          f[i - 1][j - a[i]] + a[i] * (j - a[i])
            + b[i] * (s[i - 1] - (j - a[i])));
      }
      if (j >= b[i]) {
        f[i][j] = min(f[i][j],
          f[i - 1][j - b[i]] + b[i] * (j - b[i])
            + a[i] * (s[i - 1] - (j - b[i])));
      }
    }
  }
  int ans = inf;
  for (int i = 0; i <= s[n]; i++) {
    ans = min(ans, f[n][i]);
  }
  int tmp = 0;
  for (int i = 1; i <= n; i++) {
    tmp += a[i] * a[i] + b[i] * b[i];
  }
  cout << 2 * ans + tmp * (n - 1) << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("D.in", "r", stdin);
  freopen("D.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}