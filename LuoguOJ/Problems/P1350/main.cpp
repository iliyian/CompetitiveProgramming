// date: 2024-04-01 19:04:49
// tag: dp
// wa#01: 漏了一处模

#include <bits/stdc++.h>
#define int long long
using namespace std;

constexpr int mod = 100003;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  int a, b, c, d, k;
  cin >> a >> b >> c >> d >> k;
  int n = b + d, m = a + c;
  vector<vector<int>> f(n + 1, vector<int>(m + 1));
  vector<int> w(n + 1);
  for (int i = 0; i <= n; i++) {
    f[i][0] = 1;
    w[i] = (i <= b ? a : m);
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= w[i]; j++) {
      f[i][j] = (f[i - 1][j] + f[i - 1][j - 1] * (w[i] - j + 1) % mod) % mod;
      assert(f[i][j] < INT_MAX);
    }
  }
  // for (int i = 1; i <= n; i++) {
  //   for (int j = 1; j <= m; j++) {
  //     cerr << f[i][j] << " \n"[j == m];
  //   }
  // }
  cout << f[n][k];

  return 0;
}