// date: 2025-01-25 18:22:48
// tag: 神秘的数学结论的暴力题，fib相关，打表

#include <bits/stdc++.h>
#define int long long

constexpr int mod = 1e9 + 7;

void solve() {
  int n, k;
  std::cin >> n >> k;
  n %= mod;
  if (k == 1) {
    std::cout << n % mod << '\n';
    return;
  }
  std::vector<int> f(3 * k + 1);
  f[1] = f[2] = 1;
  for (int i = 3; i <= 3 * k; i++) {
    f[i] = f[i - 1] + f[i - 2];
    f[i] %= k;
    if (!f[i]) {
      std::cout << n * i % mod << '\n';
      return;
    }
  }
  assert(false);
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  // int n = 92;
  // std::vector<int> f(n + 1);
  // f[1] = f[2] = 1;
  // for (int i = 3; i <= n; i++) {
  //   f[i] = f[i - 1] + f[i - 2];
  //   assert(f[i] > 0);
  // }
  // for (int k = 2; k <= n; k++) {
  //   std::cout << k << ": ";
  //   for (int i = 1; i <= n; i++) {
  //     if (f[i] % k == 0) {
  //       std::cout << i << ' ' << f[i];
  //       // std::cout << i << ' ';
  //       break;
  //     }
  //   }
  //   std::cout << '\n';
  // }

  int t = 1;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}