#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> c(n * 2 + 1), x(n * 2 + 1);
  std::vector<std::vector<int>> s(n * 2 + 1, std::vector<int>(n * 2 + 1));
  for (int i = 1; i <= n; i++) {
    std::cin >> c[i];
    c[i + n] = c[i];
  }
  for (int i = 1; i <= n; i++) {
    std::cin >> x[i];
    x[i + n] = x[i];
  }
  for (int i = 1; i <= n * 2; i++) {
    for (int j = 1; j <= n * 2; j++) {
      s[i][j] = s[i - 1][j];
      if (c[i] == j) {
        s[i][j]++;
      }
    }
  }
  std::vector<std::vector<int>> f(n * 2 + 1, std::vector<int>(n * 2 + 1, LLONG_MAX / 3));
  for (int i = 1; i <= n; i++) {
    f[i][i] = 1 + x[c[i]];
  }

  for (int len = 2; len <= n; len++) {
    for (int l = 1; l + len - 1 <= n * 2; l++) {
      int r = l + len - 1;
      if (c[l] == c[r]) {
        for (int i = )
      }
      for (int i = l; i <= r - 1; i++) {
        f[l][r] = std::min(f[l][r], f[l][i] + f[i + 1][r]);
      }
    }
  }
  int ans = LLONG_MAX;
  for (int i = 1; i <= n; i++) {
    ans = std::min(ans, f[i][i + n - 1]);
  }
  std::cout << ans << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  // std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}