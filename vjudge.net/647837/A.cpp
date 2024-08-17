#include <bits/stdc++.h>
#define int long long
// using namespace std;

constexpr int mod = 998244353;

int qpow(int a, int b) {
  int ans = 1;
  while (b) {
    if (b & 1)
      ans = ans * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return ans;
}

int inv(int x) { return qpow(x, mod - 2); }

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("A.in", "r", stdin);
  freopen("A.out", "w", stdout);

  int n, l, r;
  std::cin >> n >> l >> r;
  std::vector<int> a(n + r + 1);
  for (int i = 0; i <= n; i++) {
    std::cin >> a[i];
  }
  int len = r - l + 1, ans = 0;
  int invlen = inv(len);
  // std::vector<int> f(n + 2), s(n + 2);
  // auto dfs = [&](auto self, int u) -> int {
  //   if (u > n) {
  //     return 0;
  //   }
  //   if (f[u] != 0) return f[u];
  //   int sum = a[u];
  //   for (int i = u + l; i <= u + r; i++) {
  //     sum += invlen * self(self, i) % mod;
  //     sum %= mod;
  //   }
  //   f[u] = sum;
  //   return f[u];
  // };
  // std::cout << dfs(dfs, 0) << '\n';

  std::vector<int> dp(n + 1), sum(n + 2);
  for (int i = n; i >= 0; i--) {
    dp[i] =
        a[i] +
        ((sum[std::min(n + 1, i + l)] - sum[std::min(n + 1, i + r + 1)]) % mod +
         mod) %
            mod * invlen;
    dp[i] %= mod;
    sum[i] = sum[i + 1] + dp[i];
    sum[i] %= mod; // ?
  }
  std::cout << dp[0] << '\n';

  return 0;
}