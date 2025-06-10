// date: 2025-06-09 09:30:59
// tag: 什么神仙题，并查集的**自定义**用法

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::array<int, 3>> e(m + 1);
  std::vector<int> pa(n + 1), siz(n + 1, 1), mn(n + 1, LLONG_MAX / 3);
  std::iota(pa.begin(), pa.end(), 0);
  for (int i = 1; i <= m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    e[i] = {w, x, y};
  }
  std::sort(e.begin() + 1, e.end());
  auto find = [&](auto self, int x) -> int {return x == pa[x] ? x : pa[x] = self(self, pa[x]);};
  auto merge = [&](int x, int y, int w) -> bool {
    x = find(find, x), y = find(find, y);
    if (x == y) return false;
    if (siz[x] > siz[y]) std::swap(x, y);
    pa[x] = y;
    siz[y] += siz[x];
    mn[y] = std::min({mn[y], mn[x], w});
    return true;
  };

  int ans = LLONG_MAX / 3;
  for (int i = 1; i <= m; i++) {
    auto [w, x, y] = e[i];
    if (merge(x, y, w)) {
      if (find(find, 1) == find(find, n)) {
        ans = std::min(ans, w + mn[find(find, 1)]);
        // std::cout << w + mn[find(find, 1)] << '\n';
        // return;
      }
    }
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