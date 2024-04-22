// date: 2024-04-22 12:48:46
// tag: 构造

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<vector<int>> a(n * 2 + 1, vector<int>(n * 2 + 1));
  int ans = 0, t = INT_MAX;
  for (int i = 1; i <= n * 2; i++) {
    for (int j = 1; j <= n * 2; j++) {
      cin >> a[i][j];
      if (i > n && j > n) {
        ans += a[i][j];
      }
      if ((i == 1 || i == n) && (j == n + 1 || j == n * 2)) {
        t = min(t, a[i][j]);
      }
      if ((i == n + 1 || i == n * 2) && (j == 1 || j == n)) {
        t = min(t, a[i][j]);
      }
    }
  }
  cout << ans + t << '\n';
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