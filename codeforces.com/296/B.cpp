// date: 2024-05-15 22:35:45
// tag: dp

#include <bits/stdc++.h>
#define int long long
#define mod ((int)1e9 + 7)
using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("B.in", "r", stdin);
  freopen("B.out", "w", stdout);

  int n;
  string a, b;
  cin >> n >> a >> b;
  a = '#' + a, b = '#' + b;

  vector<vector<vector<int>>> f(n + 1, vector<vector<int>>(2, vector<int>(2, 0)));
  f[0][0][0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int x = 0; x <= 9; x++) {
      for (int y = 0; y <= 9; y++) {
        if ((a[i] == '?' || x == a[i] - '0') && (b[i] == '?' || y == b[i] - '0')) {
          for (int u = 0; u < 2; u++) {
            for (int v = 0; v < 2; v++) {
              auto &t = f[i][u || x < y][v || x > y]; // 类似状压
              t += f[i - 1][u][v];
              t %= mod;
            }
          }
        }
      }
    }
  }
  cout << f[n][1][1] << '\n';

  return 0;
}