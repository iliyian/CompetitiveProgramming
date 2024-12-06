#include <bits/stdc++.h>
#define int long long
#define mid (s + t) / 2
#define lc p << 1
#define rc p << 1 | 1

void solve() {
  int n, q;
  std::cin >> n >> q;
  std::vector<int> a(n + 1), b(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    b[i] = a[i] - a[i - 1];
  }
  std::vector<int> g(n << 2);
  auto query = [&](auto self, int l, int r, int s, int t, int p) -> int {
    if (l > t || r < s) return 0;
    if (l <= s && t <= r) return g[p];
    return std::gcd(self(self, l, r, s, mid, lc), self(self, l, r, mid + 1, t, rc));
  };
  auto build = [&](auto self, int s, int t, int p) {
    if (s == t) {
      g[p] = std::abs(b[s]);
      return;
    }
    self(self, s, mid, lc);
    self(self, mid + 1, t, rc);
    g[p] = std::gcd(g[lc], g[rc]);
  };
  build(build, 1, n, 1);
  while (q--) {
    int l, r;
    std::cin >> l >> r;
    if (l == r) {
      std::cout << 0 << ' ';
      continue;
    }
    std::cout << query(query, l + 1, r, 1, n, 1) << ' ';
  }
  std::cout << '\n';
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