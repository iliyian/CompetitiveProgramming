// date: 2025-04-10 07:26:22
// tag: oh~man~，竟然一遍过了，真想不到真是这个结论。区间乘变严格递增。显然-1最多用一次且只用在某一段开头，枚举-1的位置即可。然后从后往前显然遇到递减，从前往后遇到递增，需要各自+1。这也算dp吗？

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  std::vector<int> f(n + 2), g(n + 2);
  for (int i = n - 1; i >= 1; i--) {
    f[i] = f[i + 1];
    if (a[i] >= a[i + 1]) {
      f[i]++;
    }
  }
  g[1] = 1;
  for (int i = 2; i <= n; i++) {
    g[i] = g[i - 1];
    if (a[i] >= a[i - 1]) {
      g[i]++;
    }
  }
  int ans = n - 1;
  for (int i = 0; i <= n; i++) {
    // std::cerr << g[i] << ' ' << f[i + 1] << ' ' << i << '\n';
    ans = std::min(ans, g[i] + f[i + 1]);
  }
  std::cout << ans << '\n';
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