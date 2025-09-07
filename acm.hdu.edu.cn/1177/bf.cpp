#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m, k;
  std::cin >> n >> m >> k;
  std::vector<std::vector<int>> a(n, std::vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      std::cin >> a[i][j];
    }
  }
  int final = 0;
  int out = 0;
  for (int i = 0; i < (1 << n); i++) {
    if (__builtin_popcountll(i) != k) continue;
    int ans = 0;
    for (int j = 0; j < m; j++) {
      int mx = 0;
      for (int k = 0; k < n; k++) {
        if (i >> k & 1) {
          mx = std::max(mx, a[k][j]);
        }
      }
      ans += mx;
    }
    if (final < ans) {
      final = ans;
      out = i;
    }
  }
  std::cout << final << '\n';
  for (int i = 0; i < n; i++) {
    if (out >> i & 1) {
      std::cout << i + 1 << ' ';
    }
  }
  std::cout << '\n';
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