#include <bits/stdc++.h>
#define int long long

constexpr int mod = 998244353;

int C[65][65], p2[65];

void solve() {
  int n, k;
  std::cin >> n >> k;
  int ans = 0;
  // if (k == 1) {
  //   ans += (1ll << (63 - __builtin_clzll(n)));
  //   ans %= mod;
  // }
  auto solve = [&](int n, int k, int pre) {
    int ans = 0;
    if (n >= 0 && k - 1 >= 0 && k - 1 <= n) ans = (ans + p2[n + 1] * C[n][k - 1] % mod) % mod;
    if (n >= -1 && k >= 0 && k <= n + 1) ans = (ans + C[n + 1][k] * pre % mod) % mod;
    return ans;
  };
  n++;
  int pre = 0;
  for (int i = 60; i >= 0; i--) {
    if (n >> i & 1) {
      ans += solve(i - 1, k, pre);
      ans %= mod;
      k--;
      pre += 1ll << i;
      pre %= mod;
    }
  }
  std::cout << ans << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  C[0][0] = 1;
  p2[0] = 0;
  for (int i = 1; i <= 64; i++) {
    C[i][0] = C[i][i] = 1;
    p2[i] = p2[i - 1] * 2 % mod + 1;
    p2[i] %= mod;
    for (int j = 1; j <= i - 1; j++) {
      C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
      C[i][j] %= mod;
    }
  }

  int t = 1;
  std::cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}