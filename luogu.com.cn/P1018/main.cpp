#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  int n, k;
  string str;
  cin >> str;
  str = '#' + str;
  vector f(n + 1, vector<vector<int>>(n + 1, vector<int>(10)));
  for (int l = 1; l <= n; l++) {
    for (int r = l; r <= n; r++) {
      for (int mid = l; mid <= r; mid++) {
        for (int x = 1; x <= min(k, r - l + 1); x++) {
          for (int u = 1; u <= x; u++) {
            v = x - u;
            f[l][r][x] = max(f[l][r][x], f[l][mid][u] * f[mid + 1][r][x - u]);
          }
        }
      }
    }
  }

  return 0;
}