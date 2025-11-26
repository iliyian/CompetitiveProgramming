#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<std::array<int, 3>> a(n + 1);
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < 3; j++) {
      std::cin >> a[i][j];
    }
  }
  std::map<std::array<int, 3>, int> mp[8];
  std::vector<std::array<int, 8>> g(n + 1, {0, 0, 0, 0, 0, 0, 0, 0});
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < 8; j++) {
      std::array<int, 3> arr{0, 0, 0};
      for (int k = 0; k < 3; k++) {
        if (j >> k & 1) {
          arr[k] = a[i][k];
        }
      }
      mp[j][arr]++;
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < 8; j++) {
      std::array<int, 3> arr{0, 0, 0};
      for (int k = 0; k < 3; k++) {
        if (j >> k & 1) {
          arr[k] = a[i][k];
        }
      }
      g[i][j] = mp[j][arr] - 1;
    }
    for (int j = 0; j < 3; j++) {
      for (int k = 0; k < 8; k++) {
        if (k >> j & 1 ^ 1) {
          g[i][k] -= g[i][k ^ (1ll << j)];
        }
      }
    }
    int s = std::accumulate(g[i].begin() + 1, g[i].end(), 0ll);
    for (int j = 1; j < 8; j++) {
      if (__builtin_popcountll(j) >= 2) {
        ans += g[i][j] * (g[i][j] - 1) / 2;
      }
    }
    for (int j = 1; j < 8; j++) {
      for (int k = j + 1; k < 8; k++) {
        ans += g[i][j] * g[i][k];
      }
    }
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