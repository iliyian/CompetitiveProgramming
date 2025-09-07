#include <bits/stdc++.h>
// #define int long long

template<class Info>
struct SegmentTree {
    int n;
    std::vector<Info> info;
    SegmentTree() : n(0) {}
    SegmentTree(int n_, Info v_ = Info()) {
        init(n_, v_);
    }
    template<class T>
    SegmentTree(std::vector<T> init_) {
        init(init_);
    }
    void init(int n_, Info v_ = Info()) {
        init(std::vector(n_, v_));
    }
    template<class T>
    void init(std::vector<T> init_) {
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
    void pull(int p) {
        info[p] = info[2 * p] + info[2 * p + 1];
    }
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
        return rangeQuery(2 * p, l, m, x, y) + rangeQuery(2 * p + 1, m, r, x, y);
    }
    Info rangeQuery(int l, int r) {
        return rangeQuery(1, 0, n, l, r);
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

struct Info {
  Info() {
    ll = rl = len = maxlen = f = lc = rc = 0;
  }
  Info(char ch) {
    ll = rl = len = maxlen = f = 1;
    lc = rc = ch;
  }
  int ll, rl, lc, rc, len, maxlen;
  bool f;
};

int tot = 0;

Info operator+(const Info &a, const Info &b) {
  Info c;
  ++tot;
  c.lc = a.lc;
  c.rc = b.rc;
  if (a.f && a.lc == b.lc) {
    c.ll = a.len + b.ll;
  } else {
    c.ll = a.ll;
  }
  if (b.f && b.rc == a.rc) {
    c.rl = b.len + a.rl;
  } else {
    c.rl = b.rl;
  }
  c.maxlen = std::max({a.maxlen, b.maxlen, (a.rc == b.lc ? a.rl + b.ll : 0)});
  c.f = a.f && b.f && a.lc == b.rc;
  c.len = a.len + b.len;
  return c;
}

void solve() {
  int n, q;
  std::cin >> n >> q;
  std::string str;
  std::cin >> str;
  std::vector<Info> a(n);
  for (int i = 0; i < n; i++) {
    a[i] = Info(str[i]);
  }
  SegmentTree<Info> seg(a);
  while (q--) {
    int op;
    std::cin >> op;
    if (op == 1) {
      int x;
      char ch;
      std::cin >> x >> ch;
      x--;
      seg.modify(x, Info(ch));
    } else {
      int l, r;
      std::cin >> l >> r;
      l--;
      std::cout << seg.rangeQuery(l, r).maxlen << '\n';
    }
  }
  // std::cerr << tot << '\n';
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