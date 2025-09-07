#include <bits/stdc++.h>
// #define int long long
using namespace std;

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
};

struct Info {
  int l = -1, r = -1, len = 0;
  int maxlen = 0, rval[4] = {-1, -1, -1, -1}, lval[3] = {-1, -1, -1};
  Info() {}
  Info(std::tuple<int, int, int> val) {
    auto [_l, _r, _v] = val;
    len = 1;
    if (_v > 0) {
      rval[3] = lval[0] = _l;
    }
    l = _l, r = _r;
  }
};

int n;
std::vector<int> a;

inline int get(int x) {
  if (x < 0 || x >= n) return -1;
  return a[x];
}

inline bool eq4(int L, int R, int l, int r) {
  if (L < l || R > r) return false;
  int v[4] = {1, 2, 1, 0}, vv[5] = {2, 0, 2, 0};
  for (int i = 0; i < 4; i++) {
    if (get(L + i) != v[i]) {
      for (int j = 0; j < 4; j++) {
        if (get(L + j) != vv[j]) {
          return false;
        }
      }
      return true;
    }
  }
  return true;
}

inline bool eq5(int L, int R, int l, int r) {
  if (L < l || R > r) return false;
  int v[5] = {2, 1, 2, 0, 0};
  for (int i = 0; i < 5; i++) {
    if (v[i] != get(L + i)) {
      return false;
    }
  }
  return true;
}

struct MaxInfo {
  int val = -1;
  MaxInfo() {}
  MaxInfo(int x) {
    val = x;
  }
};

MaxInfo operator+(const MaxInfo &a, const MaxInfo &b) {
  return MaxInfo(std::max(a.val, b.val));
}

SegmentTree<MaxInfo> mxseg;

bool check(int a, int b, int c, int d, int l, int r) {
  int val = get(a);
  if (val == -1) return false;
  if (val >= 3 && get(b) == 2 && get(c) == 1 && get(d) == 1
    && a + 1 == b && b + 1 == c) {
    if (d - c - 1 == val - 3) {
      if (d + 3 <= r && get(d + 1) == 0 && get(d + 2) == 0 && get(d + 3) == 0) {
        if (val == 3 || mxseg.rangeQuery(c + 1, d).val <= 0) {
          return true;
        }
      }
    }
  }
  return false;
}

Info operator+(const Info &a, const Info &b) {
  if (a.len == 0) return b;
  if (b.len == 0) return a;
  Info c;
  c.maxlen = std::max(a.maxlen, b.maxlen);
  c.l = a.l, c.r = b.r, c.len = a.len + b.len;
  if (a.len + b.len >= 4) {
    for (int i = 0; i < 3; i++) {
      if (eq4(a.r - i, b.l + 2 - i, c.l, c.r)) {
        c.maxlen = std::max(c.maxlen, 4);
        break;
      }
    }
  }
  if (a.len + b.len >= 5) {
    for (int i = 0; i < 4; i++) {
      if (eq5(a.r - i, b.l + 3 - i, c.l, c.r)) {
        c.maxlen = std::max(c.maxlen, 5);
        break;
      }
    }
  }

  if (a.len + b.len >= 7) {
    if (check(a.rval[3], b.lval[0], b.lval[1], b.lval[2], c.l, c.r)) {
      c.maxlen = std::max(c.maxlen, get(a.rval[3]) + 4);
    }
    if (check(a.rval[2], a.rval[3], b.lval[0], b.lval[1], c.l, c.r)) {
      c.maxlen = std::max(c.maxlen, get(a.rval[2]) + 4);
    }
    if (check(a.rval[1], a.rval[2], a.rval[3], b.lval[0], c.l, c.r)) {
      c.maxlen = std::max(c.maxlen, get(a.rval[1]) + 4);
    }
    if (check(a.rval[0], a.rval[1], a.rval[2], a.rval[3], c.l, c.r)) {
      c.maxlen = std::max(c.maxlen, get(a.rval[0]) + 4);
    }
  }

  int j = 3;
  for (int i = 3; i >= 0; i--) {
    if (b.rval[i] != -1) {
      c.rval[i] = b.rval[i];
    } else {
      c.rval[i] = a.rval[j];
      j--;
    }
  }

  j = 0;
  for (int i = 0; i <= 2; i++) {
    if (a.lval[i] != -1) {
      c.lval[i] = a.lval[i];
    } else {
      c.lval[i] = b.lval[j];
      j++;
    }
  }

  return c;
}

void solve() {
  int q;
  std::cin >> n >> q;
  a.resize(n);
  std::vector<Info> vec(n);
  std::vector<MaxInfo> vec2(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
    vec[i] = Info({i, i, a[i]});
    vec2[i] = MaxInfo(a[i]);
  }
  mxseg.init(vec2);
  SegmentTree<Info> seg(vec);
  std::vector<std::array<int, 3>> ask(q);
  for (auto &[op, x, y] : ask) {
    std::cin >> op >> x >> y;
  }
  for (auto &[op, x, y] : ask) {
    if (op == 1) {
      int p = y;
      x--;
      a[x] = p;
      vec[x] = Info({x, x, p});
      vec2[x] = MaxInfo(p);
      mxseg.modify(x, vec2[x]);
      seg.modify(x, vec[x]);
    } else {
      int l = x, r = y;
      l--;
      std::cout << seg.rangeQuery(l, r).maxlen << '\n';
    }
  }
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int t = 1;
  std::cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}