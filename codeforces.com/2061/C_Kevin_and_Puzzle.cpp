#include <bits/stdc++.h>
#define int long long

constexpr int mod = 998244353;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  std::vector<std::array<int, 3>> f(n + 1, {0, 0, 0});
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  if (a[1]) {
    f[1][1] = 1;
  } else {
    f[1][0] = f[1][2] = 1;
  }
  // 诚实，不诚实且撒谎，不诚实没撒谎
  for (int i = 2; i <= n; i++) {
    f[i][0] += f[i - 1][1] * (a[i - 1] + 1 != a[i] && a[i - 2] + 1 == a[i]) % mod + f[i - 1][2] * (a[i - 1] + 1 == a[i]) % mod + f[i - 1][0] * (a[i - 1] == a[i]) % mod;
    f[i][0] %= mod;
    f[i][1] += f[i - 1][0] * (a[i - 1] != a[i]) % mod;
    f[i][1] %= mod;
    f[i][2] += f[i - 1][0] * (a[i - 1] == a[i]) % mod;
    f[i][2] %= mod;
  }
  // for (int i = 1; i <= n; i++) {
  //   std::cout << f[i][0] << ' ' << f[i][1] << ' ' << f[i][2] << '\n';
  // }
  std::cout << ((f[n][0] + f[n][1]) % mod + f[n][2]) % mod << '\n';
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}