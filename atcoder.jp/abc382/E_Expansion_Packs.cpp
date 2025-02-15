// date: 2025-02-14 00:05:43
// tag: 很有意思的背包概率问题，不同概率的事件同时试验一次，发生事件数的期望。然后按照次数转移转换为普通的期望dp

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, x;
  std::cin >> n >> x;
  std::vector<double> p(n + 1);
  for (int i = 1; i <= n; i++) {
    int x;
    std::cin >> x;
    p[i] = x / 100.0;
  }
  std::vector<double> g(n + 1);
  g[0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = n; j >= 1; j--) {
      g[j] = (1 - p[i]) * g[j] + p[i] * g[j - 1];
    }
    g[0] *= 1 - p[i];
  }
  // for (int i = 0; i <= n; i++) {
  //   std::cerr << g[i] << ' ';
  // }
  std::vector<double> f(x + 1);
  for (int i = 1; i <= x; i++) {
    for (int j = 1; j <= n; j++) {
      f[i] += (1 + f[std::max(0ll, i - j)]) * g[j];
    }
    f[i] = (g[0] + f[i]) / (1 - g[0]);
  }
  std::cout << std::fixed << std::setprecision(16) << f[x] << '\n';
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