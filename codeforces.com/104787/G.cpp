#include <bits/stdc++.h>
#define int long long

signed main() {
  freopen("G.in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n, m;
  std::cin >> n >> m;
  std::vector<int> a(n + 1), b(m + 1);
  int ans = 0, l = 1, r = 1;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    if (i > 1) {
      ans += std::abs(a[i] - a[i - 1]);
    }
  }
  for (int i = 1; i <= m; i++) {
    std::cin >> b[i];
    if (i > 1) {
      ans += std::abs(b[i] - b[i - 1]);
    }
  }
  std::cout << ans << '\n';
  return 0;
}