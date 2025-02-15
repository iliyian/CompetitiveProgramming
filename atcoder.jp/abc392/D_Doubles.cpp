#include <bits/stdc++.h>
#define int long long

constexpr int N = 1e5;

void solve() {
  int n;
  std::cin >> n;
  std::vector<std::map<int, int>> a(n + 1);
  std::vector<int> b(n + 1);
  for (int i = 1; i <= n; i++) {
    int K;
    std::cin >> K;
    b[i] = K;
    std::map<int, int> mp;
    for (int j = 1; j <= K; j++) {
      int x;
      std::cin >> x;
      a[i][x]++;
    }
  }
  double ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      double cur = 0;
      for (auto [k, v] : a[i]) {
        // std::cerr << k << ' ' << v << '\n';
        if (a[j].count(k)) {
          cur += 1.0 * v / b[i] * 1.0 * a[j][k] / b[j];
          // std::cerr << cur << '\n';
        }
      }
      ans = std::max(ans, cur);
    }
    // std::cerr << cur << '\n';
  }
  std::cout << std::fixed << std::setprecision(20) << ans << '\n';
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