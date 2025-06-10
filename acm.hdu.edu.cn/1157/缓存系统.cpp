#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m, x;
  std::cin >> n >> m >> x;
  std::vector<std::vector<int>> s(n + 1, std::vector<int>(m + 1));
  std::vector<std::vector<int>> a(n + 1, std::vector<int>(m + 1));
  int sum = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      std::cin >> s[i][j] >> a[i][j];
      s[i][j] += s[i][j - 1];
      a[i][j] += a[i][j - 1];
    }
    sum += a[i][m];
  }
  std::vector<int> f(x + 1);
  for (int i = 1; i <= n; i++) {
    for (int j = x; j >= 0; j--) {
      for (int k = 1; k <= m; k++) {
        if (j - s[i][k] >= 0) {
          f[j] = std::max(f[j], f[j - s[i][k]] + a[i][k]);
        }
      }
    }
  }
  int mx = 0;
  for (int i = 0; i <= x; i++) {
    mx = std::max(mx, f[i]);
  }
  std::cout << sum - mx << '\n';
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