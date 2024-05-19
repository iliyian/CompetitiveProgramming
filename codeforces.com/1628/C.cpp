// date: 2024-05-19 19:57:55
// tag: 构造

#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("C.in", "r", stdin);
  freopen("C.out", "w", stdout);

  int T;
  cin >> T;

  while (T--) {
    int n;
    cin >> n;
    vector<vector<int>> a(n + 1, vector<int>(n + 1));
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        cin >> a[i][j];
      }
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        if (i > j && (i - j - 1) % 4 == 0 && i % 2 == 0
          || i < j && (j - i + 1) % 4 == 0 && j % 2 == 0) {
            ans ^= a[i][j] ^ a[i][n - j + 1];
            // cout << i << ' ' << j << '\n';
        }
      }
    }
    cout << ans << '\n';
  }

  return 0;
}