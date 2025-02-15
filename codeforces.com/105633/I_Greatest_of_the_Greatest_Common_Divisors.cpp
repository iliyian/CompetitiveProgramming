// date: 2025-01-26 17:40:38
// tag: 线段树上二分，一种根据r分组的离线区间询问思想

#include <bits/stdc++.h>
#define int long long
#define lc p << 1
#define rc p << 1 | 1
#define mid (s + t) / 2

constexpr int N = 1e5;
std::vector<std::vector<int>> fac(N + 1);

struct Seg {
  int mx = -1;
  Seg operator + (const Seg &b) const {
    return Seg{std::max(mx, b.mx)};
  }
};

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  int q;
  std::cin >> q;
  std::vector<int> ans(q + 1);
  std::vector<std::vector<std::pair<int, int>>> ask(n + 1);
  for (int i = 1; i <= q; i++) {
    int l, r;
    std::cin >> l >> r;
    ask[r].push_back({l, i});
  }
  int r = 0;
  std::vector<Seg> d(N << 2);
  auto add = [&](auto &&self, int s, int t, int p, int x, int c) -> void {
    if (x > t || x < s) return;
    if (s == t) {
      d[p].mx = std::max(d[p].mx, c);
      return;
    }
    self(self, s, mid, lc, x, c);
    self(self, mid + 1, t, rc, x, c);
    d[p] = d[lc] + d[rc];
  };
  auto query = [&](auto &&self, int s, int t, int p, int l) -> int {
    if (s == t) return s;
    if (d[rc].mx >= l) return self(self, mid + 1, t, rc, l);
    return self(self, s, mid, lc, l);
  };
  std::vector<int> r1(N + 1, -1), r2(N + 1, -1);
  for (int r = 1; r <= n; r++) {
    for (int i : fac[a[r]]) {
      if (r > r1[i]) {
        r2[i] = r1[i];
        r1[i] = r;
      } else if (r > r2[i]) {
        r2[i] = r;
      }
      if (r2[i] != -1) {
        add(add, 1, N, 1, i, r2[i]);
      }
    }
    for (auto [l, id] : ask[r]) {
      ans[id] = query(query, 1, N, 1, l);
    }
  }
  for (int i = 1; i <= q; i++) {
    std::cout << ans[i] << '\n';
  }
  std::cout << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  for (int i = 1; i <= N; i++) {
    for (int j = i; j <= N; j += i) {
      fac[j].push_back(i);
    }
  }

  int t = 1;
  // std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}