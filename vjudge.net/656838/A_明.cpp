#include <bits/stdc++.h>
#define int long long

template<class Info, class Tag>
struct LazySegmentTree {
    int n;
    std::vector<Info> info;
    std::vector<Tag> tag;
    LazySegmentTree() : n(0) {}
    LazySegmentTree(int n_, Info v_ = Info()) {
        init(n_, v_);
    }
    template<class T>
    LazySegmentTree(std::vector<T> init_) {
        init(init_);
    }
    void init(int n_, Info v_ = Info()) {
        init(std::vector(n_, v_));
    }
    template<class T>
    void init(std::vector<T> init_) {
        n = init_.size();
        info.assign(4 << std::__lg(n), Info());
        tag.assign(4 << std::__lg(n), Tag());
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
    void pull(int p) {
        info[p] = info[2 * p] + info[2 * p + 1];
    }
    void apply(int p, const Tag &v) {
        info[p].apply(v);
        tag[p].apply(v);
    }
    void push(int p) {
        apply(2 * p, tag[p]);
        apply(2 * p + 1, tag[p]);
        tag[p] = Tag();
    }
    void modify(int p, int l, int r, int x, const Info &v) {
        if (r - l == 1) {
            info[p] = v;
            return;
        }
        int m = (l + r) / 2;
        push(p);
        if (x < m) {
            modify(2 * p, l, m, x, v);
        } else {
            modify(2 * p + 1, m, r, x, v);
        }
        pull(p);
    }
    void modify(int p, const Info &v) {
        modify(1, 0, n, p, v);
    }
    Info rangeQuery(int p, int l, int r, int x, int y) {
        if (l >= y || r <= x) {
            return Info();
        }
        if (l >= x && r <= y) {
            return info[p];
        }
        int m = (l + r) / 2;
        push(p);
        return rangeQuery(2 * p, l, m, x, y) + rangeQuery(2 * p + 1, m, r, x, y);
    }
    Info rangeQuery(int l, int r) {
        return rangeQuery(1, 0, n, l, r);
    }
    void rangeApply(int p, int l, int r, int x, int y, const Tag &v) {
        if (l >= y || r <= x) {
            return;
        }
        if (l >= x && r <= y) {
            apply(p, v);
            return;
        }
        int m = (l + r) / 2;
        push(p);
        rangeApply(2 * p, l, m, x, y, v);
        rangeApply(2 * p + 1, m, r, x, y, v);
        pull(p);
    }
    void rangeApply(int l, int r, const Tag &v) {
        return rangeApply(1, 0, n, l, r, v);
    }
    template<class F>
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
        push(p);
        int res = findFirst(2 * p, l, m, x, y, pred);
        if (res == -1) {
            res = findFirst(2 * p + 1, m, r, x, y, pred);
        }
        return res;
    }
    template<class F>
    int findFirst(int l, int r, F &&pred) {
        return findFirst(1, 0, n, l, r, pred);
    }
    template<class F>
    int findLast(int p, int l, int r, int x, int y, F &&pred) {
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
        push(p);
        int res = findLast(2 * p + 1, m, r, x, y, pred);
        if (res == -1) {
            res = findLast(2 * p, l, m, x, y, pred);
        }
        return res;
    }
    template<class F>
    int findLast(int l, int r, F &&pred) {
        return findLast(1, 0, n, l, r, pred);
    }
};
 
struct Tag {
  bool flip = 0, r0 = 0, r1 = 0;
  void apply(const Tag &t) & {
    if (t.flip) {
      if (r0 | r1) {
        r0 ^= 1, r1 ^= 1;
      } else {
        flip ^= 1;
      }
    }
    if (t.r0) {
      r0 = 1;
      r1 = 0;
      flip = 0;
    }
    if (t.r1) {
      r1 = 1;
      r0 = 0;
      flip = 0;
    }
  }
};
 
struct Info { 
  int llen = 0, rlen = 0, len = 0, anslen = 0, lv = -1, rv = -1;
  Info() {}
  Info(int x) : llen(1), rlen(1), len(1), anslen(1), lv(x & 1), rv(x & 1) {}
  void apply(const Tag &t) & {
    if (t.flip) {
      lv ^= 1, rv ^= 1;
    }
    if (t.r1) {
      llen = rlen = anslen = 1;
      lv = rv = 1;
    }
    if (t.r0) {
      llen = rlen = anslen = 1;
      lv = rv = 0;
    }
  }
};
 
Info operator+(const Info &a, const Info &b) {
  if (a.len == 0) return b;
  if (b.len == 0) return a;
  Info c;
  c.len = a.len + b.len;
  c.anslen = std::max(a.anslen, b.anslen);
  c.llen = a.llen, c.rlen = b.rlen;
  c.lv = a.lv, c.rv = b.rv;
  if (a.rv ^ b.lv) {
    c.anslen = std::max(c.anslen, a.rlen + b.llen);
    if (a.llen == a.len) {
      c.llen = a.llen + b.llen;
    }
    if (b.rlen == b.len) {
      c.rlen = b.rlen + a.rlen;
    }
  }
  return c;
}

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<Info> a(n + 1);
  for (int i = 1; i <= n; i++) {
    int x;
    std::cin >> x;
    a[i] = Info(x);
  }
  LazySegmentTree<Info, Tag> tr(a);
  for (int i = 1; i <= m; i++) {
    int op;
    std::cin >> op;
    if (op == 1 || op == 3) {
      int l, r, x;
      std::cin >> l >> r >> x;
      if (x & 1) {
        tr.rangeApply(l, r + 1, Tag{1, 0, 0});
      }
    }
    if (op == 2) {
      int l, r, x;
      std::cin >> l >> r >> x;
      if (x & 1 ^ 1) {
        tr.rangeApply(l, r + 1, Tag{0, 1, 0});
      }
    }
    if (op == 4) {
      int l, r;
      std::cin >> l >> r;
      std::cout << tr.rangeQuery(l, r + 1).anslen << '\n';
    }
  }
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