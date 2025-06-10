#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m, k;
  std::cin >> n >> m >> k;
  std::vector<std::array<int, 3>> e(m);
  for (int i = 0; i < m; i++) {
    std::cin >> e[i][0] >> e[i][1] >> e[i][2];
    e[i][2] %= k;
  }
  std::vector<int> pa(n + 1), siz(n + 1, 1);
  auto find = [&](auto self, int x) -> int {return x == pa[x] ? x : pa[x] = self(self, pa[x]);};
  auto merge = [&](int x, int y) -> bool {
    x = find(find, x), y = find(find, y);
    if (x == y) return false;
    if (siz[x] > siz[y]) std::swap(x, y);
    siz[y] += siz[x];
    pa[x] = y;
    return true;
  };
  int sum = LLONG_MAX;
  for (int S = 0; S < (1 << m); S++) {
    if (__builtin_popcountll(S) != n - 1) continue;
    std::iota(pa.begin() + 1, pa.end(), 1);
    std::fill(siz.begin() + 1, siz.end(), 1);
    bool f = true;
    int res = 0;
    for (int i = 0; i < m; i++) {
      if (S >> i & 1) {
        if (merge(e[i][0], e[i][1])) {
          res += e[i][2];
          res %= k;
        } else f = false;
      }
    }
    if (f) {
      sum = std::min(sum, res);
    }
  }
  std::cout << sum << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  // std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}