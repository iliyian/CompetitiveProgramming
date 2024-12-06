// date: 2024-12-04 21:18:37
// tag: 挺有意思的dp，关键在于推出其前缀性，从而将多个操作简化与整合

#include <bits/stdc++.h>
#define int long long
#define mid (s + t) / 2
#define lc p << 1
#define rc p << 1 | 1

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1), b(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    a[i] += a[i - 1];
  }
  for (int i = 1; i <= n; i++) {
    std::cin >> b[i];
  }
  std::vector<int> mx(n << 2, INT_MIN);
  auto modify = [&](auto self, int x, int s, int t, int p, int c) -> void {
    if (x > t || x < s) return;
    if (s == t) {
      mx[p] = std::max(mx[p], c); // you may set it directly?
      return;
    }
    self(self, x, s, mid, lc, c);
    self(self, x, mid + 1, t, rc, c);
    mx[p] = std::max(mx[lc], mx[rc]);
  };
  auto query = [&](auto self, int l, int r, int s, int t, int p) -> int {
    if (l > t || r < s) return INT_MIN;
    if (l <= s && t <= r) return mx[p];
    return std::max(self(self, l, r, s, mid, lc), self(self, l, r, mid + 1, t, rc));
  };
  std::vector<int> f(n + 1);
  for (int i = n; i >= 1; i--) {
    f[i] = a[i];
    if (b[i] > i) {
      f[i] = std::max(f[i], query(query, i + 1, b[i], 1, n, 1) - (a[i] - a[i - 1]));
    }
    modify(modify, i, 1, n, 1, f[i]);
  }
  std::cout << f[1] << '\n';
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