#include <bits/stdc++.h>
#define int long long

signed main() {
  int x, y, z, n, m;
  std::cin >> x >> y >> z >> n >> m;

  int ans = 0;
  for (int i = 0; i <= m; i++) {
    for (int j = 0; j <= m - i; j++) {
      int k = m - i - j;
      if (k % z) continue;
      if (i * x + j * y + k / z == n) {
        ans++;
      }
    }
  }
  std::cout << ans << '\n';

  return 0;
}