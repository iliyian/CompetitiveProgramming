// date: 2024-04-03 21:42:12
// tag: 构造，树上距离，贪心

#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  int n;
  cin >> n;
  vector<vector<int>> a(n + 1, vector<int>(n + 1));
  for (int i = 1; i <= n - 1; i++) {
    for (int j = i + 1; j <= n; j++) {
      cin >> a[i][j];
      a[j][i] = a[i][j];
    }
  }
  int ans = a[1][2];
  for (int i = 3; i <= n; i++) {
    int len = INT_MAX;
    for (int j = 2; j < i; j++) {
      len = min(len, (a[i][j] + a[i][j - 1] - a[j][j - 1]) / 2);
    }
    ans += len;
  }
  cout << ans << '\n';

  return 0;
}