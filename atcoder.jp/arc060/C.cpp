#include <algorithm>
#include <bits/stdc++.h>

signed main() {
  freopen("C.in", "r", stdin);
  int n;
  std::cin >> n;
  std::vector<int> x(n + 1);
  std::vector<std::vector<int>> nxt(n + 1, std::vector<int>(21));
  for (int i = 1; i <= n; i++) {
    std::cin >> x[i];
  }
  int l, q;
  std::cin >> l >> q;
  for (int i = 1; i <= n; i++) {
    nxt[i][0] = std::upper_bound(x.begin() + 1, x.end(), x[i] + l) - x.begin() - 1;
  }
  for (int j = 1; j <= 20; j++) {
    for (int i = 1; i <= n; i++) {
      if (nxt[i][j - 1] <= n) {
        nxt[i][j] = nxt[nxt[i][j - 1]][j - 1];
      }
    }
  }
  while (q--) {
    int a, b;
    std::cin >> a >> b;
    int ans = 1;
    if (a > b) std::swap(a, b);
    for (int i = 20; i >= 0; i--) {
      if (nxt[a][i] < b) {
        ans += 1 << i;
        a = nxt[a][i];
      }
    }
    std::cout << ans << '\n';
  }
  return 0;
}