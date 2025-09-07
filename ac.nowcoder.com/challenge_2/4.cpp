#include <bits/stdc++.h>
#define int long long
#define lc p << 1
#define rc p << 1 | 1
#define mid (s + t) / 2

struct Tag {
  int val = 0;
  void apply(const Tag &t) {
    val += t.val;
  }
};

struct Info {
  int mx1 = 0, mx2 = 0;
  void apply(const Tag &t) {
    mx1 += t.val;
    if (mx2 != 0) {
      mx2 += t.val;
    }
  }
};

Info operator+(const Info &a, const Info &b) {
  if (a.mx1 == 0) return b;
  if (b.mx1 == 0) return a;
  Info c;
  int v[4] = {a.mx1, a.mx2, b.mx1, b.mx2};
  std::sort(v, v + 4);
  c.mx1 = v[3];
  int i = 2;
  while (i >= 0 && v[i] == v[3]) i--;
  if (i == -1) {
    c.mx2 = 0;
  } else {
    c.mx2 = v[i];
  }
  return c;
}

void solve() {
  int n, q;
  std::cin >> n >> q;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  std::vector<Info> d(n << 2);
  std::vector<Tag> tags(n << 2);
  auto pushup = [&](int p) {
    d[p] = d[lc] + d[rc];
  };
  auto build = [&](auto self, int s, int t, int p) -> void {
    if (s == t) {
      d[p] = Info{a[s], 0};
      return;
    }
    self(self, s, mid, lc);
    self(self, mid + 1, t, rc);
    pushup(p);
  };
  build(build, 1, n, 1);
  auto apply2 = [&](int p, const Tag &tag) {
    d[p].apply(tag);
    tags[p].apply(tag);
  };
  auto pushdown = [&](int p) {
    apply2(lc, tags[p]);
    apply2(rc, tags[p]);
    tags[p] = Tag{0};
  };
  auto apply = [&](auto self, int l, int r, int s, int t, int p, const Tag &tag) -> void {
    if (l > t || r < s) return;
    if (l <= s && t <= r) {
      d[p].apply(tag);
      tags[p].apply(tag);
      return;
    }
    pushdown(p);
    self(self, l, r, s, mid, lc, tag);
    self(self, l, r, mid + 1, t, rc, tag);
    pushup(p);
  };
  auto query = [&](auto self, int l, int r, int s, int t, int p) -> Info {
    if (l > t || r < s) return Info{0, 0};
    if (l <= s && t <= r) return d[p];
    pushdown(p);
    return self(self, l, r, s, mid, lc) + self(self, l, r, mid + 1, t, rc);
  };
  while (q--) {
    int op;
    std::cin >> op;
    if (op == 1) {
      int l, r, x;
      std::cin >> l >> r >> x;
      apply(apply, l, r, 1, n, 1, Tag{x});
    } else {
      int l, r;
      std::cin >> l >> r;
      if (l == r) {
        std::cout << 0 << '\n';
        continue;
      }
      std::cout << query(query, l, r, 1, n, 1).mx2 << '\n';
    }
  }
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int t = 1;
  // std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}