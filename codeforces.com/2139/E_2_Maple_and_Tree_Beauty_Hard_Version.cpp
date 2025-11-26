// date: 2025-09-09 18:57:10
// tag: tmd凭什么这么简单，随便转换一下是吧，跟D一样
// 二进制优化大概优化个四分之一常数？

#include <bits/stdc++.h>
#define int long long

constexpr int N = 2e5;

void solve() {
  int n, k;
  std::cin >> n >> k;
  std::vector<std::vector<int>> g(n + 1);
  for (int i = 2; i <= n; i++) {
    int x;
    std::cin >> x;
    g[x].push_back(i);
  }
  std::vector<int> a(n + 1), dep(n + 1);
  std::queue<std::pair<int, int>> q;
  q.push({1, 1});
  int mn = N + 1;
  while (!q.empty()) {
    auto [d, u] = q.front(); q.pop();
    dep[u] = d;
    a[d]++;
    if (g[u].empty()) {
      mn = std::min(mn, d);
    }
    for (int v : g[u]) {
      q.push({d + 1, v});
    }
  }
  auto tot = std::accumulate(a.begin() + 1, a.begin() + mn + 1, 0ll);
  std::bitset<N + 1> dp;
  dp[0] = 1;
  int ans = 0;
  std::vector<int> c(n + 1);
  for (int i = 1; i <= mn; i++) {
    c[a[i]]++;
  }
  for (int i = 1; i <= n; i++) {
    if (c[i]) {
      int x = c[i];
      for (int k = 1; k <= x; k *= 2) {
        dp |= dp << (k * i);
        x -= k;
      }
      dp |= dp << (x * i);
    }
  }
  for (int i = 0; i <= std::min(k, tot); i++) {
    if (tot - i <= n - k && dp.test(i)) {
      std::cout << mn << '\n';
      return;
    }
  }
  std::cout << mn - 1 << '\n';
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