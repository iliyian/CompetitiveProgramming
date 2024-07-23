// date: 2024-07-23 10:22:26
// tag: dp

#include <bits/stdc++.h>
#define int long long
// using namespace std;

constexpr int mod = 998244353;

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int n, k;
  std::cin >> n >> k;

  std::vector<std::vector<int>> f(n + 1, std::vector<int>(k + 1));
  std::vector<int> sum(k + 1);
  sum[0] = f[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= k; j++) {
      int &t = f[i][std::min(j + 1, k)];
      t += sum[j];
      t %= mod;
      if (i > 2 && i != n) {
        t -= f[i - 2][j];
        t = (t % mod + mod) % mod;
      }
    }
    for (int j = 0; j <= k; j++) {
      sum[j] += f[i][j];
      sum[j] %= mod;
    }
  }

  // std::cout << ans << '\n';
  std::cout << f[n][k] << '\n';
  

  return 0;
}