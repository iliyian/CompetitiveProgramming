// date: 2025-04-20 12:23:29
// tag: 只能说相当思维的一道题，性质观察，奇偶

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> x(n + 1), y(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> x[i] >> y[i];
    y[i] += x[i];
  }
  int u = 0, v = 0;
  for (int i = 1; i <= n; i++) {
    u ^= x[i], v ^= y[i];
  }
  std::cout << u << ' ' << v - u << '\n';
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