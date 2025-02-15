#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<int>> a(n + 1, std::vector<int>(m + 1));
  std::vector<int> s(n + 1);
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      std::cin >> a[i][j];
      ans += a[i][j] * (m - j + 1);
      s[i] += a[i][j];
    }
  }
  std::vector<int> p(n + 1);
  std::iota(p.begin() + 1, p.end(), 1);
  std::sort(p.begin() + 1, p.end(), [&](const int &x, const int &y) {
    return s[x] < s[y];
  });
  for (int i = 1; i <= n; i++) {
    ans += (i - 1) * m * s[p[i]];
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