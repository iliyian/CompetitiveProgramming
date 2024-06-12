// date: 2024-06-06 20:19:55
// tag: 贪心

#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  freopen("K.in", "r", stdin);
  freopen("K.out", "w", stdout);

  int n;
  cin >> n;
  vector<vector<int>> a(n + 1, vector<int>(n + 1));
  int mn = LLONG_MAX, sum = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> a[i][j];
      sum += a[i][j];
      if (i + j == n + 1) {
        mn = min(mn, a[i][j]);
      }
    }
  }
  cout << sum - mn << '\n';

  return 0;
}