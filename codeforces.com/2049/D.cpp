#include <bits/stdc++.h>
#define int long long

constexpr int inf = 0x3f3f3f3f3f3f3f3f;

void solve() {
  int n, m, k;
  std::cin >> n >> m >> k;
  std::vector<std::vector<int>> a(n + 1, std::vector<int>(m + 1));
  std::vector<std::vector<std::vector<int>>> f(n + 1, std::vector<std::vector<int>>(m + 1, std::vector<int>(m, inf)));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      std::cin >> a[i][j];
    }
  }
  for (int i = 0; i < m; i++) {
    f[0][0][i] = 0;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      for (int k = 0; k < m; k++) {
        f[i][j][k] = f[i - 1][j][]
      }
    }
  }
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