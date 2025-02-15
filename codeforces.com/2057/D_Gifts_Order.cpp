// date: 2025-01-20 17:18:06
// tag: 区间极差减长度

#include <bits/stdc++.h>
#define int long long
#define lc p << 1
#define rc p << 1 | 1
#define mid (s + t) / 2

struct Seg {
  int mnv, mxv, v;
};

void solve() {
  int n, q;
  std::cin >> n >> q;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  std::vector<Seg> d1(n << 2), d2(n << 2);
  auto pushup = [&](this auto &&self, int p) {
    d1[p] = {
      std::min(d1[lc].mnv, d1[rc].mnv),
      std::max(d1[lc].mxv, d1[rc].mxv),
      std::max({d1[lc].v, d1[rc].v, d1[rc].mxv - d1[lc].mnv}),
    };
    d2[p] = {
      std::min(d2[lc].mnv, d2[rc].mnv),
      std::max(d2[lc].mxv, d2[rc].mxv),
      std::max({d2[lc].v, d2[rc].v, d2[lc].mxv - d2[rc].mnv}),
    };
  };
  auto build = [&](this auto &&self, int s, int t, int p) {
    if (s == t) {
      d1[p] = {a[s] - s, a[s] - s, 0};
      d2[p] = {a[s] + s, a[s] + s, 0};
      return;
    }
    self(s, mid, lc);
    self(mid + 1, t, rc);
    pushup(p);
  };
  auto modify = [&](this auto &&self, int s, int t, int p, int x, int c) {
    if (x > t || x < s) return;
    if (s == t) {
      d1[p] = {c - s, c - s, 0};
      d2[p] = {c + s, c + s, 0};
      return;
    }
    self(s, mid, lc, x, c);
    self(mid + 1, t, rc, x, c);
    pushup(p);
  };
  build(1, n, 1);
  std::cout << std::max(d1[1].v, d2[1].v) << ' ';
  // std::cout << d1[1].mnv << ' ' << d1[1].mxv << ' ' << d1[1].v << '\n';
  // std::cout << d2[1].mnv << ' ' << d2[1].mxv << ' ' << d2[1].v << '\n';
  while (q--) {
    int p, x;
    std::cin >> p >> x;
    modify(1, n, 1, p, x);
    std::cout << std::max(d1[1].v, d2[1].v) << ' ';
    // std::cout << d1[1].mnv << ' ' << d1[1].mxv << ' ' << d1[1].v << '\n';
    // std::cout << d2[1].mnv << ' ' << d2[1].mxv << ' ' << d2[1].v << '\n';
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