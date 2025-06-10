#include <bits/stdc++.h>
#define int long long
#define lc p << 1
#define rc p << 1 | 1
#define mid (s + t) / 2

void solve() {
  int n, q;
  std::cin >> n >> q;
  std::vector<int> a(n + 1), d(n << 2);
  auto modify = [&](auto self, int x, int s, int t, int p, int c) -> void {
    if (x > t || x < s) return;
    if (s == t) {
      d[p] = c;
      return;
    }
    self(self, x, s, mid, lc, c);
    self(self, x, mid + 1, t, rc, c);
    d[p] = d[lc] + d[rc];
  };
  auto query = [&](auto self, int l, int r, int s, int t, int p) -> int {
    if (l > r) return 0;
    if (l > t || r < s) return 0;
    if (l <= s && t <= r) {
      return d[p];
    }
    return self(self, l, r, s, mid, lc) + self(self, l, r, mid + 1, t, rc);
  };
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  auto build = [&](auto self, int s, int t, int p) -> void {
    if (s == t) {
      d[p] = a[s];
      return;
    }
    self(self, s, mid, lc);
    self(self, mid + 1, t, rc);
    d[p] = d[lc] + d[rc];
  };
  build(build, 1, n, 1);
  int res = 0, idx = 0;
  for (int i = 1; i <= q; i++) {
    int op, x, y;
    std::cin >> op >> x >> y;
    if (op == 1) {
      modify(modify, x, 1, n, 1, y);
    } else {
      int r = query(query, 1, y, 1, n, 1);
      int l = query(query, 1, x - 1, 1, n, 1);
      // std::cerr << l << ' ' << r << '\n';
      int ans = (r / 100) - (l / 100);
      // std::cerr << ans << '\n';
      res ^= ans * (++idx);
    }
  }
  std::cout << res << '\n';
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