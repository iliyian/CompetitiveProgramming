// date: 2025-01-31 21:00:49
// tag: 多个并查集的暴力，关键在于通过不同操作的相同性质使其可结合，从而降低时间复杂度

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<std::vector<std::pair<int, int>>>> v(11, std::vector<std::vector<std::pair<int, int>>>(11));
  while (m--) {
    int a, d, k;
    std::cin >> a >> d >> k;
    v[d][a % d].push_back({a, a + k * d});
  }
  std::vector<int> pa(n + 1), siz(n + 1, 1);
  std::iota(pa.begin(), pa.end(), 0);
  auto find = [&](this auto &&self, int x) -> int {return x == pa[x] ? x : pa[x] = self(pa[x]);};
  auto merge = [&](int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return;
    if (siz[x] > siz[y]) std::swap(x, y);
    siz[y] += siz[x];
    pa[x] = y;
  };
  for (int k = 1; k <= 10; k++) {
    for (int re = 0; re < k; re++) {
      int _l = -1, _r = -1;
      std::sort(v[k][re].begin(), v[k][re].end());
      for (auto [l, r] : v[k][re]) {
        if (l > _r) {
          if (_l != -1) {
            for (int i = _l; i <= _r; i += k) {
              merge(_l, i);
            }
          }
          _l = l;
        }
        _r = std::max(_r, r);
      }
      // std::cerr << _l << ' ' << _r << '\n';
      if (_l != -1) {
        for (int i = _l; i <= _r; i += k) {
          merge(_l, i);
        }
      }
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += find(i) == i;
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