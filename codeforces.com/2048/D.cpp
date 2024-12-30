#include <algorithm>
#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<int> a(n + 1), b(m + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  for (int i = 1; i <= m; i++) {
    std::cin >> b[i];
    if (b[i] <= a[1]) b[i] = INT_MAX;
  }
  std::sort(a.begin() + 2, a.end());
  std::sort(b.begin() + 1, b.end());
  a.erase(a.begin() + 2, std::lower_bound(a.begin() + 2, a.end(), a[1]));
  std::vector<int> c(m + 1);
  for (int i = 1; i <= m; i++) {
    c[i] = a.end() - std::lower_bound(a.begin() + 2, a.end(), b[i]);
  }
  std::sort(c.begin() + 1, c.end());
  for (int k = 1; k <= m; k++) {
    int ans = 0;
    for (int i = k; i <= m; i += k) {
      ans += c[i] + 1;
    }
    std::cout << ans << ' ';
  }
  std::cout << '\n';
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
