#include <bits/stdc++.h>
#define int long long

signed main() {
  freopen("E.in", "r", stdin);
  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<int>> f(n + 1, std::vector<int>(n + 1));
  for (int i = 1; i <= m; i++) {
    int op, a, b, c;
    std::cin >> op >> a >> b >> c;
    if (op == 1) f[a][b] += c;
    else f[a][b] -= c;
    int ans = INT_MIN;
    for (int x = 1; x <= n; x++) {
      for (int y = 1; y <= n; y++) {
        ans = std::max(ans, f[x][y]);
      }
    }
    std::cout << ans << '\n';
  }
  return 0;
}