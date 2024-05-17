// date: 2024-05-16 13:59:03
// tag: dp

#include <bits/stdc++.h>
using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("C.in", "r", stdin);
  freopen("C.out", "w", stdout);

  int n;
  cin >> n;
  vector<int> a(n + 1);
  vector<vector<int>> f(n + 1, vector<int>(n + 1));
  vector<vector<int>> g(n + 1, vector<int>(n + 1));
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int sum = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      f[i][j] = f[i - 1][j] + (a[i] < a[j]);
      g[i][j] = g[i - 1][j] + (a[i] > a[j]);
    }
  }
  for (int i = 1; i <= n; i++) {
    sum += g[i - 1][i];
  }
  int ans = sum;
  for (int l = 1; l <= n; l++) {
    for (int r = l + 1; r <= n; r++) {
      int nxt = sum + g[r][l] - g[l][l] - (f[r][l] - f[l][l])
        + f[r][r] - f[l][r] - (g[r][r] - g[l][r]);
      if (nxt < ans) {
        ans = nxt;
      }
    }
  }

  int cnt = 0;
  for (int l = 1; l <= n; l++) {
    for (int r = l + 1; r <= n; r++) {
      int nxt = sum + g[r][l] - g[l][l] - (f[r][l] - f[l][l])
        + f[r][r] - f[l][r] - (g[r][r] - g[l][r]);
      if (nxt == ans) {
        cnt++;
      }
    }
  }
  cout << ans << ' ' << cnt << '\n';

  return 0;
}