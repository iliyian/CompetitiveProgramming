#include <bits/stdc++.h>
#define int long long

signed main() {
  freopen("B.in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n, m, k;
  std::cin >> n >> m >> k;
  std::vector<int> pos(m + 1), ans(m + 1);
  for (int i = 1; i <= k; i++) {
    int p, c;
    std::cin >> p >> c;
    if (!pos[c]) pos[c] = p;
    else {
      if (p == pos[c]) {
        ans[c] += 100;
      } else {
        ans[c] += std::abs(p - pos[c]);
      }
      pos[c] = 0;
    }
  }
  for (int i = 1; i <= m; i++) {
    if (pos[i]) {
      ans[i] += 100;
    }
  }
  for (int i = 1; i <= m; i++) {
    std::cout << ans[i] << ' ';
  }
  return 0;
}