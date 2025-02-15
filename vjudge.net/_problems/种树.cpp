// date: 2025-02-15 12:41:49
// tag: 最少的点覆盖最多的区间的问题，从按照[l,r]从小往大排后，倒序尽可能放在左侧，很经典的一类提

#include <bits/stdc++.h>
#define int long long
#define lc p << 1
#define rc p << 1 | 1
#define mid (s + t) / 2

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::array<int, 3>> a(m + 1);
  for (int i = 1; i <= m; i++) {
    int l, r, t;
    std::cin >> l >> r >> t;
    a[i] = {l, r, t};
  }
  std::vector<int> d(n << 2), b(n + 1);
  auto add = [&](auto self, int x, int s, int t, int p, int c) -> void {
    if (x > t || x < s) return;
    if (s == t) {
      d[p] += c;
      return;
    }
    self(self, x, s, mid, lc, c);
    self(self, x, mid + 1, t, rc, c);
    d[p] = d[lc] + d[rc];
  };
  auto query = [&](auto self, int l, int r, int s, int t, int p) -> int {
    if (l > t || r < s) return 0;
    if (l <= s && t <= r) return d[p];
    return self(self, l, r, s, mid, lc) + self(self, l, r, mid + 1, t, rc);
  };
  std::sort(a.begin() + 1, a.end());
  int ans = 0;
  // for (int i = 1; i <= m; i++) {
  for (int i = m; i >= 1; i--) {
    auto [l, r, s] = a[i];
    s -= query(query, l, r, 1, n, 1);
    // std::cerr << l << ' ' << r << ' ' << s << '\n';
    for (int j = l; j <= r && s > 0; j++) {
      if (!b[j]) {
        add(add, j, 1, n, 1, 1);
        b[j] = 1;
        ans++;
        s--;
      }
    }
  }
  // for (int i = 1; i <= n; i++) {
  //   std::cerr << b[i] << " \n"[i == n];
  // }
  std::cout << ans << '\n';
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