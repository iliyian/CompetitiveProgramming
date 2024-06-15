// date: 2024-06-15 23:05:41
// tag: 动态规划，
// 没法转移就再加一维！！
// 不一定是数组，可以是循环的时候多考虑一个变量

#include <bits/stdc++.h>
#define int long long
#define mod 998244353
#define N 1000
using namespace std;

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  freopen("E.in", "r", stdin);
  freopen("E.out", "w", stdout);

  int K;
  cin >> K;
  vector<int> c(27);
  for (int i = 1; i <= 26; i++) {
    cin >> c[i];
  }
  vector<vector<int>> C(N + 1, vector<int>(N + 1));
  for (int i = 1; i <= N; i++) {
    C[i][0] = C[i][i] = 1;
    for (int j = 1; j <= i - 1; j++) {
      C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
    }
  }

  vector<vector<int>> f(27, vector<int>(K + 1));
  for (int i = 0; i <= 26; i++) {
    f[i][0] = 1;
  }
  for (int i = 1; i <= 26; i++) {
    for (int j = 1; j <= K; j++) {
      for (int k = 0; k <= min(c[i], j); k++) {
        f[i][j] += f[i - 1][j - k] * C[j][k] % mod;
        f[i][j] %= mod; 
      }
    }
  }
  int ans = 0;
  for (int i = 1; i <= K; i++) {
    ans += f[26][i] % mod;
    ans %= mod;
  }
  cout << ans << '\n';
  

  return 0;
}