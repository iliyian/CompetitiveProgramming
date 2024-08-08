// date: 2024-08-06 13:02:30
// tag: 数学

#include <algorithm>
#include <bits/stdc++.h>
#define int long long
// using namespace std;

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("E.in", "r", stdin);
  freopen("E.out", "w", stdout);

  int n, m, q;
  std::cin >> n >> m >> q;
  std::vector<int> a(n + 1), b(m + 2);
  int asum = 0;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    asum += (i & 1 ? a[i] : -a[i]);
  }
  for (int i = 1; i <= m; i++) {
    std::cin >> b[i];
    b[i] = b[i - 1] + b[i] * (i & 1 ? 1 : -1);
  }
  std::vector<int> c(m - n + 1);
  for (int i = 0; i <= m - n; i++) {
    c[i] = (b[n + i] - b[i]) * (i & 1 ? -1 : 1);
  }
  std::sort(c.begin(), c.end());

  auto solve = [&](int l, int r, int x) {
    if ((r - l + 1) % 2) {
      asum += (l & 1 ? x : -x);
    }
    auto p = std::lower_bound(c.begin(), c.end(), asum);
    int ans = LLONG_MAX;
    if (p != c.end()) ans = std::min(ans, *p - asum);
    if (p != c.begin()) ans = std::min(ans, asum - *std::prev(p));
    std::cout << ans << '\n';
  };

  solve(0, 0, 0);
  while (q--) {
    int l, r, x;
    std::cin >> l >> r >> x;
    solve(l, r, x);
  }

  return 0;
}