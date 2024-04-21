// date: 2024-04-15 21:31:14
// tag: 动态规划，排列组合
// 处理小于等于和等于的关系
// wa#01: 顺便组合数记得取模

#include <bits/stdc++.h>
#define int long long
#define mod 998244353
using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("E.in", "r", stdin);
  freopen("E.out", "w", stdout);

  int n, x;
  cin >> n >> x;
  vector<vector<int>> C(n + 1, vector<int>(n + 1));
  for (int i = 1; i <= n; i++) {
    C[i][0] = C[i][i] = 1;
    for (int j = 1; j < i; j++) {
      C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
      C[i][j] %= mod;
    }
  }
  auto qpow = [](int a, int b) {
    int ans = 1;
    while (b) {
      if (b & 1) ans = ans * a % mod;
      a = a * a % mod;
      b >>= 1;
    }
    return ans;
  };
  vector<vector<int>> f(n + 1, vector<int>(x + 1));
  for (int i = 2; i <= n; i++) {
    for (int j = 1; j <= x; j++) {
      if (i > j) {
        f[i][j] = qpow(j, i) - qpow(j - 1, i); // 恰好
        f[i][j] = (f[i][j] % mod + mod) % mod;
      } else for (int k = 1; k <= i; k++) {
        f[i][j] += f[k][j - (i - 1)] % mod
          * C[i][k] % mod
          * qpow(i - 1, i - k) % mod;
        f[i][j] %= mod;
      }
    }
  }
  int ans = 0;
  for (int i = 1; i <= x; i++) {
    ans += f[n][i];
    ans %= mod;
  }
  cout << ans << '\n';

  return 0;
}