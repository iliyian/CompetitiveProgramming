#include <bits/stdc++.h>
#define int long long
using namespace std;

int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> a(n + 2, vector<int>(m + 2));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      bool f = true;
      int mx = 0;
      for (int d = 0; d < 4; d++) {
        int xx = i + dx[d], yy = j + dy[d];
        mx = max(mx, a[xx][yy]);
        if (a[xx][yy] >= a[i][j]) {
          f = false;
        }
      }
      if (f) {
        a[i][j] = mx;
      }
      cout << a[i][j] << ' ';
    }
    cout << '\n';
  }
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  freopen("B.in", "r", stdin);
  freopen("B.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}