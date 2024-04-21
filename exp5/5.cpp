#include <bits/stdc++.h>
using namespace std;

void solve() {
  string a, b;
  cin >> a >> b;
  int n = a.size(), m = b.size();
  vector<vector<int>> f(n + 1, vector<int>(m + 1, 0));
  for (int i = 0; i < n; i++)
    f[i][0] = a[i] == b[0];
  for (int i = 0; i < m; i++)
    f[0][i] = a[0] == b[i];
  int ans = 0;
  for (int i = 1; i < n; i++)
    for (int j = 1; j < m; j++) {
      f[i][j] = (a[i] == b[j] ? f[i - 1][j - 1] + 1 : 0);
      ans = max(ans, f[i][j]);
    }
  cout << ans;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("5.in", "r", stdin);
  freopen("5.out", "w", stdout);
  // int _; cin >> _;
  int _ = 1;
  while (_--) solve();
}