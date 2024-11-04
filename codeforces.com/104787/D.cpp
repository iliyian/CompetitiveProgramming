#include <bits/stdc++.h>
#define int long long
#define lc p << 1
#define rc p << 1 | 1
#define mid (s + t) / 2

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<int> a(n + 1);
  std::vector<std::pair<int, int>> b(m + 1);
  std::vector<int> mn(n << 2), tag(n << 2, 0);
  auto pushup = [&](int p) {
    mn[p] = std::min(mn[lc], mn[rc]);
  };
  auto build = [&](auto self, int s, int t, int p) {
    if (s == t) {
      mn[p] = a[s];
      return;
    }
    self(self, s, mid, lc);
    self(self, mid + 1, t, rc);
    pushup(p);
  };
  auto P = [&](int p, int c) {
    mn[p] += c;
    tag[p] += c;
  };
  auto pushdown = [&](int p) {
    if (tag[p]) {
      P(lc, tag[p]);
      P(rc, tag[p]);
      tag[p] = 0;
    }
  };
  auto add = [&](auto self, int l, int r, int s, int t, int p, int c) {
    if (l > t || r < s) return;
    if (l <= s && t <= r) {
      P(p, c);
      return;
    }
    pushdown(p);
    self(self, l, r, s, mid, lc, c);
    self(self, l, r, mid + 1, t, rc, c);
    pushup(p);
  };
  auto query = [&](auto self, int l, int r, int s, int t, int p) -> int {
    if (l > t || r < s) return INT_MAX;
    if (l <= s && t <= r) return mn[p];
    pushdown(p);
    return std::min(self(self, l, r, s, mid, lc) ,self(self, l, r, mid + 1, t, rc));
  };
  auto queryidx = [&](auto self, int l, int r, int s, int t, int p) -> int {
    if (l > t || r < s) return INT_MAX;
    if (l <= s && t <= r) return mn[p];
    pushdown(p);
  };
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  for (int i = 1; i <= m; i++) {
    std::cin >> b[i].first >> b[i].second;
  }
  build(build, 1, n, 1);
  std::sort(b.begin() + 1, b.end());
  for (int i = 1; i <= m; i++) {
    auto &[r, w] = b[i];
    add(add, 1, r, 1, n, 1, -w);
  }
  for (int i = 1; i <= n; i++) {
    
  }
}

signed main() {
  freopen("D.in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}