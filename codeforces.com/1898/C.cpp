#include <bits/stdc++.h>
using namespace std;

int c[20][20], v[20][20];

void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  if (k < n + m - 2) {
    cout << "NO" << '\n';
    return;
  }
  if ((n + m - k) & 1) {
    cout << "NO" << '\n';
    return;
  }
  cout << "YES\n";
  for (int i = 1; i <= m - 1; i++)
    c[1][i] = i & 1;
  for (int i = m; i <= n + m - 2; i++)
    v[i - m + 1][m] = i & 1;
  c[2][1] = c[1][1] ^ 1;
  v[1][1] = v[1][2] = c[1][1];
  v[n - 1][m - 1] = v[n - 1][m];
  c[n][m - 1] = c[n - 1][m - 1] = (v[n - 1][m] ^ 1);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m - 1; j++)
      cout << (c[i][j] ? 'R' : 'B') << " \n"[j == m - 1];
  for (int i = 1; i <= n - 1; i++)
    for (int j = 1; j <= m; j++)
      cout << (v[i][j] ? 'R' : 'B') << " \n"[j == m];
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("C.in", "r", stdin);
  freopen("C.out", "w", stdout);
  int _; cin >> _;
  while (_--) solve();
}