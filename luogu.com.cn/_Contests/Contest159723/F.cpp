#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("F.in", "r", stdin);
  freopen("F.out", "w", stdout);

  int n, m, k;
  cin >> n >> m >> k;
  vector a(n + 1, vector<int>(m + 1));
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    int mx = -0x3f3f3f3f;
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
      if (j == 1) {
        mx = a[i][j] - k;
      } else {
        mx = max(mx, a[i][j] - k * j);
      }
    }
    ans += mx;
  }
  cout << ans << '\n';

  return 0;
}