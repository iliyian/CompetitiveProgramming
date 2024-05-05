// date: 2024-05-04 15:34:58
// tag: dp

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<vector<int>> a(n + 1, vector<int>(2));
  for (int j = 0; j < 2; j++) {
    for (int i = 1; i <= n; i++) {
      char x;
      cin >> x;
      a[i][j] = x == '*';
    }
  }
  vector<vector<int>> f(n + 2, vector<int>(2));
  int i = 1;
  while (i <= n && !a[i][1] && !a[i][0]) i++;
  if (a[i][0] == a[i][1]) {
    f[i][0] = f[i][1] = a[i][0];
  } else {
    f[i][0] = a[i][1], f[i][1] = a[i][0];
  }
  i++;
  for (; i <= n; i++) {
    for (int j = 0; j < 2; j++) {
      f[i][j] = min(f[i - 1][j ^ 1] + 2, f[i - 1][j] + (a[i][j ^ 1] ? 2 : 1));
    }
  } // reversable
  for (int i = n; i >= 1; i--) {
    if (a[i][1] || a[i][0]) {
      cout << min(f[i][1], f[i][0]) << '\n';
      return;
    }
  }
  cout << 0 << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("E.in", "r", stdin);
  freopen("E.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}