// date: 2025-05-20 19:54:17
// tag: 从后往前dp以取消界限跳来跳去的问题，方便确定可划分的子状态。果然状态转移可以从各个角度来看。

#include <bits/stdc++.h>
#define int long long

constexpr int mod = 998244353;
int C[502][502] {};

void solve() {
  int n, k;
  std::cin >> n >> k;
  std::vector<std::vector<int>> f(n + 2, std::vector<int>(k + 1));
  f[n + 1][0] = 1;
  std::string str;
  std::cin >> str;
  str = '#' + str;
  for (int p = n; p >= 1; p--) {
    for (int i = 1; i <= k; i++) {
      for (int j = 0; j < i; j++) {
        f[p][i] += f[p + 1][j] * C[(i + (str[p] == '0')) / 2][i - j] % mod;
        f[p][i] %= mod;
      }
    }
    for (int i = 0; i <= k; i++) {
      f[p][i] += f[p + 1][i];
      f[p][i] %= mod;
    }
  }
  // for (int t = 1; t <= k; t++) {
  //   for (int i = 1; i <= n; i++) {
  //     std::cerr << f[i][t] << " \n"[i == n];
  //   }
  // }
  std::cout << f[1][k] << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  C[0][0] = 1;
  for (int i = 1; i <= 500; i++) {
    C[i][0] = C[i][i] = 1;
    for (int j = 1; j < i; j++) {
      C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
    }
  }

  int t = 1;
  std::cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}