#include <bits/stdc++.h>
using namespace std;

int c[20][20], v[20][20];

void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  if (k < n + m - 2) {
    cout << "NO\n";
    return;
  }
  int d = m + n - k;
  if (d & 1) {
    cout << "NO\n";
    return;
  }
  cout << "YES\n";
  memset(c, 0, sizeof(c)), memset(v, 0, sizeof(v));
  int t = (k - n - m) / 4, col = 0;
  for (int i = 0; i < m - 1; i++) {
    c[0][i] = col;
    col ^= 1;
  }
  for (int j = 0; j < n - 1; j++) {
    v[j][m - 1] = col;
    col ^= 1;
  }
  c[1][0] = c[0][0];
  v[0][0] = v[0][1] = (c[0][0] ^ 1);
  v[n - 2][m - 2] = v[n - 2][m - 1] ^ 1;
  c[n - 1][m - 2] = c[n - 2][m - 2] = v[n - 2][m - 1];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m - 1; j++)
      cout << (c[i][j] ? 'R' : 'B') << " \n"[j == m - 2];
  for (int i = 0; i < n - 1; i++)
    for (int j = 0; j < m; j++)
      cout << (v[i][j] ? 'R' : 'B') << " \n"[j == m - 1];
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("C.in", "r", stdin);
  freopen("C.out", "w", stdout);
  int _; cin >> _;
  while (_--) solve();
}