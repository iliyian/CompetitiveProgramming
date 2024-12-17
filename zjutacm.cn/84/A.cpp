#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m;
  std::cin >> n >> m;
  int ans = 0;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= m; i++) {
    std::cin >> a[i];
  }
  auto dis = [&](int x, int y) {
    if (x > y) std::swap(x, y);
    return std::min(y - x, x + n - y);
  };
  for (int i = 1; i <= m; i++) {
    ans += dis(a[i], a[i % m + 1]);
  }
  std::cout << ans << '\n';
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  // std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}