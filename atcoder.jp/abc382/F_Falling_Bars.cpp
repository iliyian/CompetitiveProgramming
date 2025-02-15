// date: 2025-02-14 14:36:20
// tag: 相当少见的线段树区间修单点查的题目了属于是

#include <bits/stdc++.h>
#define int long long
#define lc p << 1
#define rc p << 1 | 1
#define mid (s + t) / 2

void solve() {
  int h, w, n;
  std::cin >> h >> w >> n;
  std::vector<std::array<int, 4>> a(n + 1);
  for (int i = 1; i <= n; i++) {
    int r, c, l;
    std::cin >> r >> c >> l;
    a[i] = {r, c, l, i};
  }
  std::sort(a.begin() + 1, a.end(), std::greater<>());
  std::vector<int> d(w << 2, h + 1), tag(w << 2, -1);
  auto P = [&](int p, int c) -> void {
    d[p] = std::min(d[p], c);
    if (tag[p] == -1) tag[p] = c;
    else tag[p] = std::min(tag[p], c);
  };
  auto pushdown = [&](int p) -> void {
    if (tag[p] != -1) {
      P(lc, tag[p]);
      P(rc, tag[p]);
      tag[p] = -1;
    }
  };
  auto pushup = [&](int p) -> void {
    d[p] = std::min(d[lc], d[rc]);
  };
  auto query = [&](auto self, int l, int r, int s, int t, int p) -> int {
    if (l > t || r < s) return h + 1;
    if (l <= s && t <= r) return d[p];
    pushdown(p);
    return std::min(self(self, l, r, s, mid, lc), self(self, l, r, mid + 1, t, rc));
  };
  auto modify = [&](auto self, int l, int r, int s, int t, int p, int c) -> void {
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
  std::vector<int> ans(n + 1);
  for (int i = 1; i <= n; i++) {
    auto [r, c, len, id] = a[i];
    // if (id == 1) {
    //   for (int i = 1; i <= w; i++) {
    //     std::cerr << query(query, i, i, 1, w, 1) << ' ';
    //   }
    //   std::cerr << '\n';
    // }
    ans[id] = query(query, c, c + len - 1, 1, w, 1) - 1;
    // std::cerr << id << ' ' << ans[id] << '\n';
    modify(modify, c, c + len - 1, 1, w, 1, ans[id]);
  }
  for (int i = 1; i <= n; i++) {
    std::cout << ans[i] << '\n';
  }
  // std::cout << '\n';
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