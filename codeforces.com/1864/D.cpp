#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<vector<int>> a(n + 2, vector<int>(n + 2)),
    b(n + 2, vector<int>(n + 2));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      char ch;
      cin >> ch;
      a[i][j] = ch - '0';
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      a[i][j] ^= b[i][j];
      ans += a[i][j];
      b[i][j] ^= a[i][j];
      
      b[i + 1][j - 1] ^= b[i][j];
      b[i + 1][j + 1] ^= b[i][j];
      a[i + 1][j] ^= b[i][j];
      if (i < n && j != 1 && j != n) {
        b[i + 2][j] ^= b[i][j];
      }
    }
  }
  cout << ans << '\n';
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