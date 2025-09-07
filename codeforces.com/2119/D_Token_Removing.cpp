#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<int>> f(n + 2, std::vector<int>(n + 2));
  f[n][0] = 1;
  for (int j = 1; j <= n; j++) {
    for (int i = n - j; i >= 1; i--) {
      f[i][j] = f[i + 1][j] + f[i + 1][j - 1] * (n - i + 1 - j) % m * i % m;
      f[i][j] %= m;
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      // std::cerr << f[i][j] << " \n"[j == n];
    }
  }
  int ans = 0;
  for (int i = 0; i <= n; i++) {
    ans += f[1][i];
    ans %= m;
  }
  std::cout << ans << '\n';
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