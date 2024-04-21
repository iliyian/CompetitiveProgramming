#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("B.in", "r", stdin);
  freopen("B.out", "w", stdout);

  int n, m;
  cin >> n >> m;
  cout << (abs(n - m) <= 1 ? "Brown" : "Alice") << '\n';

  // vector<vector<int>> t(300, vector<int>(300));
  // t[0][1] = t[1][0] = t[1][1] = -1;

  // auto check = [&](auto self, int n, int m) -> int {
  //   if (t[n][m]) return t[n][m];
  //   if (n < m) swap(n, m);
  //   for (int i = 1; i * 2 <= n; i++) {
  //     if (self(self, n - i * 2, m + i) == -1) {
  //       t[n][m] = t[m][n] = 1;
  //       return 1;
  //     }
  //   }
  //   t[n][m] = t[m][n] = -1;
  //   return -1;
  // };

  // for (int i = 0; i <= 100; i++) {
  //   for (int j = 0; j <= 100; j++) {
  //     if (check(check, i, j) == -1) {
  //       cout << i << ' ' << j << '\n';
  //     }
  //   }
  // }

  return 0;
}