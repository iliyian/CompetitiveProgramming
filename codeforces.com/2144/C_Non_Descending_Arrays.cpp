#include <bits/stdc++.h>
#define int long long

constexpr int mod = 998244353;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1), b(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    std::cin >> b[i];
  }
  std::vector<std::array<int, 2>> f(n + 1, {0, 0});
  f[1][0] = f[1][1] = 1;
  for (int i = 2; i <= n; i++) {
    for (int j = 0; j < 2; j++) {
      for (int k = 0; k < 2; k++) {
        int x = a[i - 1], y = b[i - 1];
        if (j) std::swap(x, y);
        int z = a[i], w = b[i];
        if (k) std::swap(z, w);
        if (x <= z && y <= w) {
          f[i][k] += f[i - 1][j];
          f[i][k] %= mod;
        }
      }
    }
  }
  std::cout << (f[n][0] + f[n][1]) % mod << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int t = 1;
  std::cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}