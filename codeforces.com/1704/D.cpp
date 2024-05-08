// date: 2024-05-08 17:38:12
// tag: 势能，构造

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> a(n + 1, vector<int>(m + 1));
  vector<int> c(n + 1);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
      c[i] += a[i][j] * j;
    }
  }
  for (int i = 1; i <= n - 2; i++) {
    if (c[i] != c[i + 1] || c[i + 1] != c[i + 2]) {
      if (c[i] == c[i + 1]) {
        cout << i + 2 << ' ' << abs(c[i] - c[i + 2]) << '\n';
      } else if (c[i + 1] == c[i + 2]) {
        cout << i << ' ' << abs(c[i] - c[i + 1]) << '\n';
      } else {
        cout << i + 1 << ' ' << abs(c[i] - c[i + 1]) << '\n';
      }
      return;
    }
  }
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