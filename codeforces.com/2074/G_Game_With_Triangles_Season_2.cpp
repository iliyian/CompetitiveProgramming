#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  std::vector<std::vector<int>> f(n + 1, std::vector<int>(n + 1));
  // for (int i = 1; i + 2 <= n; i++) {
  //   f[i][i + 2] = a[i] * a[i + 1] * a[i + 2];
  // }
  for (int len = 3; len <= n; len++) {
    for (int l = 1; l + len - 1 <= n; l++) {
      int r = l + len - 1;
      for (int i = l; i <= r - 1; i++) {
        f[l][r] = std::max(f[l][r], f[l][i] + f[i + 1][r]);
      }
      for (int i = l + 1; i <= r - 1; i++) {
        f[l][r] = std::max(f[l][r], f[l + 1][i - 1] + f[i + 1][r - 1] + a[l] * a[i] * a[r]);
      }
    }
  }
  std::cout << f[1][n] << '\n';
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