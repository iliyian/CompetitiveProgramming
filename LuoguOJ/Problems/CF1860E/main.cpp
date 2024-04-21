#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n;
  cin >> n;
  array<string, 2> a;
  vector<vector<int>> s(2, vector<int>(n + 1));
  cin >> a[0] >> a[1];
  a[0] = '#' + a[0];
  a[1] = '#' + a[1];
  int c1 = 0, c2 = 0;
  for (int i = 0; i < 2; i++) {
    for (int j = 1; j <= n; j++) {
      s[i][j] = s[i][j - 1] + (a[i][j] == '*');
      if (a[i][j] == '*')
        i ? c2 += j - 1 : c1 += j - 1;
    }
  }
  int ans = c1 + c2 + min(s[0][n], s[1][n]);
  for (int i = 2; i <= n; i++) {
    c1 += s[0][i - 1] - (s[0][n] - s[0][i - 1]);
    c2 += s[1][i - 1] - (s[1][n] - s[1][i - 1]);
    ans = min(ans, c1 + c2 + min(s[0][n], s[1][n]));
  }
  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}