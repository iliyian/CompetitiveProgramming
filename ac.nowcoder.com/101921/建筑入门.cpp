// date: 2025-02-18 20:49:09
// tag: 带方案的可行性完全背包

#include <bits/stdc++.h>
#define int long long

constexpr int N = 1e6;

void solve() {
  int n, k;
  std::cin >> n >> k;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    a[i] = i;
    k -= i * i;
  }
  for (int i = n - 1; i >= 1; i--) {
    a[i] += a[i + 1];
  }
  // for (int i = 1; i <= n; i++) {
  //   std::cerr << a[i] << " \n"[i == n];
  // }
  // std::cerr << k << '\n';
  std::vector<int> ans(n + 1, 1), f(N + 1);
  ans[0] = 0;
  std::vector<std::bitset<N + 1>> g(n + 1);
  f[0] = 1;
  for (int i = n; i >= 1; i--) {
    for (int j = a[i]; j <= k; j++) {
      if (f[j - a[i]]) {
        g[i][j] = 1;
        f[j] = 1;
      }
    }
  }
  // for (int i = 1; i <= k; i++) {
  //   std::cerr << f[i] << " \n"[i == k];
  // }
  int x = k;
  for (int i = 1; i <= n; i++) {
    while (x >= a[i] && g[i][x]) {
      x -= a[i];
      ans[i]++;
      // std::cerr << i << ' ';
    }
  }
  for (int i = 1; i <= n; i++) {
    ans[i] += ans[i - 1];
    k -= (ans[i] - i) * i;
  }
  if (k) {
    std::cout << -1 << '\n';
    return;
  }
  for (int i = 1; i <= n; i++) {
    std::cout << ans[i] << " \n"[i == n];
  }
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