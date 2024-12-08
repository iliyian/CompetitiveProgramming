#include <bits/stdc++.h>
#define int long long

void solve() {
  int m, n;
  std::cin >> m >> n;
  std::vector<int> a(m + 1);
  for (int i = 1; i <= m; i++) {
    std::cin >> a[i];
  }
  std::sort(a.begin() + 1, a.end());
  for (int i = 1; i <= m; i++) {
    a[i] += a[i - 1];
  }
  std::vector<int> b(n + 1), c(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> b[i];
  }
  for (int i = 1; i <= n; i++) {
    std::cin >> c[i];
  }
  int x;
  std::cin >> x;
  int sum = 0;
  for (int i = 1; i <= n; i++) {
    if (c[i] > m) {
      std::cout << "No\n";
      return;
    }
    int rest = c[i] - 1;
    int cost = a[1] * (b[i] - rest) + (a[c[i]] - a[1]) * 1;
    sum += cost;
  }
  std::cout << (sum <= x ? "Yes" : "No") << '\n';
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