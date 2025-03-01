#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n, m, q;
  cin >> n >> m >> q;
  vector<vector<int>> a(m + 1, vector<int>(n + 1));
  for (int i = 1; i <= n; i++) {
    cin >> a[0][i];
  }
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      int x;
      cin >> x;
      a[i][j] = a[i - 1][j] + x;
    }
  }
  for (int i = 0; i < q; i++) {
    int x, y, z;
    cin >> x >> y >> z;
    cout << a[x][y] - a[x][z] << '\n';
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("F.in", "r", stdin);
  freopen("F.out", "w", stdout);

  int t = 1;

  while (t--) {
    solve();
  }

  return 0;
}