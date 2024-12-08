// date: 2024-12-07 21:44:58
// tag: 线段树上超多信息合并的板子题

#include <bits/stdc++.h>
#define int long long

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

template <class Info> struct SegmentTree {
  int n;
  std::vector<Info> info;
  SegmentTree() : n(0) {}
  SegmentTree(int n_, Info v_ = Info()) { init(n_, v_); }
  template <class T> SegmentTree(std::vector<T> init_) { init(init_); }
  void init(int n_, Info v_ = Info()) { init(std::vector(n_, v_)); }
  template <class T> void init(std::vector<T> init_) {
    n = init_.size();
    info.assign(4 << std::__lg(n), Info());
    std::function<void(int, int, int)> build = [&](int p, int l, int r) {
      if (r - l == 1) {
        info[p] = init_[l];
        return;
      }
      int m = (l + r) / 2;
      build(2 * p, l, m);
      build(2 * p + 1, m, r);
      pull(p);
    };
    build(1, 0, n);
  }
  void pull(int p) { info[p] = info[2 * p] + info[2 * p + 1]; }
  void modify(int p, int l, int r, int x, const Info &v) {
    if (r - l == 1) {
      info[p] = v;
      return;
    }
    int m = (l + r) / 2;
    if (x < m) {
      modify(2 * p, l, m, x, v);
    } else {
      modify(2 * p + 1, m, r, x, v);
    }
    pull(p);
  }
  void modify(int p, const Info &v) { modify(1, 0, n, p, v); }
  Info rangeQuery(int p, int l, int r, int x, int y) {
    if (l >= y || r <= x) {
      return Info();
    }
    if (l >= x && r <= y) {
      return info[p];
    }
    int m = (l + r) / 2;
    return rangeQuery(2 * p, l, m, x, y) + rangeQuery(2 * p + 1, m, r, x, y);
  }
  Info rangeQuery(int l, int r) { return rangeQuery(1, 0, n, l, r); }
  template <class F>
  int findFirst(int p, int l, int r, int x, int y, F &&pred) {
    if (l >= y || r <= x) {
      return -1;
    }
    if (l >= x && r <= y && !pred(info[p])) {
      return -1;
    }
    if (r - l == 1) {
      return l;
    }
    int m = (l + r) / 2;
    int res = findFirst(2 * p, l, m, x, y, pred);
    if (res == -1) {
      res = findFirst(2 * p + 1, m, r, x, y, pred);
    }
    return res;
  }
  template <class F> int findFirst(int l, int r, F &&pred) {
    return findFirst(1, 0, n, l, r, pred);
  }
  template <class F> int findLast(int p, int l, int r, int x, int y, F &&pred) {
    if (l >= y || r <= x) {
      return -1;
    }
    if (l >= x && r <= y && !pred(info[p])) {
      return -1;
    }
    if (r - l == 1) {
      return l;
    }
    int m = (l + r) / 2;
    int res = findLast(2 * p + 1, m, r, x, y, pred);
    if (res == -1) {
      res = findLast(2 * p, l, m, x, y, pred);
    }
    return res;
  }
  template <class F> int findLast(int l, int r, F &&pred) {
    return findLast(1, 0, n, l, r, pred);
  }
};

constexpr int inf = 0x3f3f3f3f3f3f3f3f;

struct Info {
  int ans = -inf, sum = 0, pre = -inf, pre1 = -inf, suf = -inf, suf1 = -inf, mid = -inf, mx = -inf;
  Info() {};
  Info(const std::pair<int, int> &x) {
    mx = x.first + x.second * 2;
    pre = suf = x.first + x.second;
    sum = x.first;
  }
};

Info operator+(const Info &l, const Info &r) {
  Info c;
  c.ans = std::max({l.ans, r.ans, l.pre1 + r.suf, l.pre + r.suf1, l.mx + r.mx});
  c.mx = std::max({l.mx, r.mx, l.pre + r.suf});
  c.pre1 = std::max({r.pre1, l.pre + r.mid, l.mx + r.pre, l.pre1 + r.sum});
  c.suf1 = std::max({l.suf1, l.sum + r.suf1, l.suf + r.mx, l.mid + r.suf});
  c.pre = std::max({r.pre, l.pre + r.sum});
  c.suf = std::max({l.suf, l.sum + r.suf});
  c.mid = std::max({l.sum + r.mid, l.mid + r.sum, l.suf + r.pre});
  c.sum = l.sum + r.sum;
  return c;
}

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n), b(n);
  std::vector<std::pair<int, int>> info(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    std::cin >> b[i];
    info[i] = {a[i], b[i]};
  }
  SegmentTree<Info> seg(info);
  int q;
  std::cin >> q;
  while (q--) {
    int op, x, y;
    std::cin >> op >> x >> y;
    x--;
    if (op == 1) {
      a[x] = y;
      seg.modify(x, std::pair{a[x], b[x]});
    } else if (op == 2) {
      b[x] = y;
      seg.modify(x, std::pair{a[x], b[x]});
    } else {
      std::cout << seg.rangeQuery(x, y).ans << '\n';
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