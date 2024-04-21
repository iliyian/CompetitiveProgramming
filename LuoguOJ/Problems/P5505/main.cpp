// date: 2024-03-14 12:46:02
// tag: 容斥，补集
// wa#01: 没有考虑到带模的减法可能导致负数
// wa#02-04: 组合数范围算小了

#include <bits/stdc++.h>
#define int long long
#define mod 1000000007
using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  int n, m;
  cin >> n >> m;
  vector<int> a(m + 1);
  vector<vector<int>> C(2005, vector<int>(2005));
  C[0][0] = 1;
  for (int i = 1; i <= 2000; i++) {
    C[i][0] = C[i][i] = 1;
    for (int j = 1; j <= i; j++) {
      C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
    }
  }

  vector<int> f(n);
  for (int i = 1; i <= m; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    f[i] = C[n][i];
    for (int j = 1; j <= m; j++) {
      f[i] = f[i] * C[a[j] + n - i - 1][n - i - 1] % mod;
    }
    // cerr << f[i] << '\n';
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    ans = (ans + f[i] * (i & 1 ? -1 : 1) + mod) % mod;
  }
  cout << ans << '\n';

  return 0;
}