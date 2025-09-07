// date: 2025-08-07 11:56:29
// tag: 零索引下，0作为加法操作的幺元被占用了，还是比较麻烦的，推荐1索引捏

#include <bits/stdc++.h>
#define int long long

template <class Info, class Tag> struct LazySegmentTree {
  int n;
  std::vector<Info> info;
  std::vector<Tag> tag;
  LazySegmentTree() : n(0) {}
  LazySegmentTree(int n_, Info v_ = Info()) { init(n_, v_); }
  template <class T> LazySegmentTree(std::vector<T> init_) { init(init_); }
  void init(int n_, Info v_ = Info()) { init(std::vector(n_, v_)); }
  template <class T> void init(std::vector<T> init_) {
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
  void pull(int p) { info[p] = info[2 * p] + info[2 * p + 1]; }
  void apply(int p, const Tag &v, int len) {
    info[p].apply(v, len);
    tag[p].apply(v, len);
  }
  void push(int p, int len) {
    apply(2 * p, tag[p], len / 2);
    apply(2 * p + 1, tag[p], len - len / 2);
    tag[p] = Tag();
  }
  void modify(int p, int l, int r, int x, const Info &v) {
    if (r - l == 1) {
      info[p] = v;
      return;
    }
    int m = (l + r) / 2;
    push(p, r - l);
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
    push(p, r - l);
    return rangeQuery(2 * p, l, m, x, y) + rangeQuery(2 * p + 1, m, r, x, y);
  }
  Info rangeQuery(int l, int r) { return rangeQuery(1, 0, n, l, r); }
  void rangeApply(int p, int l, int r, int x, int y, const Tag &v) {
    if (l >= y || r <= x) {
      return;
    }
    if (l >= x && r <= y) {
      apply(p, v, r - l);
      return;
    }
    int m = (l + r) / 2;
    push(p, r - l);
    rangeApply(2 * p, l, m, x, y, v);
    rangeApply(2 * p + 1, m, r, x, y, v);
    pull(p);
  }
  void rangeApply(int l, int r, const Tag &v) {
    return rangeApply(1, 0, n, l, r, v);
  }
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
    push(p, r - l);
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
    push(p, r - l);
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

struct Tag {
  int vx = -1, vy = -1;
  void apply(const Tag &t, int len) & {
    if (t.vx != -1) {
      vx = t.vx;
    }
    if (t.vy != -1) {
      vy = t.vy;
    }
  }
};

struct Info {
  int sx = 0, sy = 0, sxy = 0, x = LLONG_MAX, y = -1;
  void apply(const Tag &t, int len) & {
    if (t.vy != -1) {
      y = t.vy;
      sy = y * len;
      sxy = y * sx;
    }
    if (t.vx != -1) {
      x = t.vx;
      sx = x * len;
      sxy = x * sy;
    }
  }
};

Info operator+(const Info &a, const Info &b) {
  // if (a.y == -1) return b;
  // if (b.y == -1) return a;
  // if (a.sx == -1 && b.sx == -1) return Info();
  Info c;
  c.sx = a.sx + b.sx;
  c.sy = a.sy + b.sy;
  c.sxy = a.sxy + b.sxy;
  c.x = std::min(a.x, b.x);
  c.y = std::max(a.y, b.y);
  return c;
}

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1), p(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    // a[i]--;
    p[a[i]] = i;
  }
  int ans = 0;
  std::stack<int> s;
  std::vector<int> L(n + 1), R(n + 1);
  for (int i = 1; i <= n; i++) {
    while (!s.empty() && a[s.top()] > a[i]) {
      R[a[s.top()]] = i; // closest
      s.pop();
    }
    s.push(i);
  }
  while (!s.empty()) {
    R[a[s.top()]] = n + 1;
    s.pop();
  }
  for (int i = n; i >= 1; i--) {
    while (!s.empty() && a[s.top()] > a[i]) {
      L[a[s.top()]] = i;
      s.pop();
    }
    s.push(i);
  }
  while (!s.empty()) {
    L[a[s.top()]] = 0;
    s.pop();
  }
  for (int i = 1; i <= n; i++) {
    // std::cerr << "i=" << i << ',' << "R[i]=" << R[i] << ',' << "L[i]=" << L[i] << ',' << "p[i]=" << p[i] << '\n';
    ans += i * (R[i] - p[i]) * (p[i] - L[i]);
  }
  // std::cerr << "preans=" << ans << '\n';
  // for (int i = 0; i < n; i++) {
  //   std::cerr << L[a[i]] << ' ' << R[a[i]] << '\n';
  // }
  // std::cerr << '\n';
  LazySegmentTree<Info, Tag> tr(n + 1);

  std::vector<std::vector<int>> stmn(20, std::vector<int>(n + 1));
  std::vector<std::vector<int>> stmx(20, std::vector<int>(n + 1));
  for (int i = 1; i <= n; i++) {
    stmn[0][i] = p[i];
    stmx[0][i] = p[i];
  }
  for (int k = 0; k < 20; k++) {
    for (int i = 2 << k; i <= n; i++) {
      stmx[k + 1][i] = std::max(stmx[k][i - (1 << k)], stmx[k][i]);
      stmn[k + 1][i] = std::min(stmn[k][i - (1 << k)], stmn[k][i]);
    }
  }
  auto getmn = [&](int l, int r) {
    int len = std::__lg(r - l + 1);
    return std::min(stmn[len][l + (1 << len) - 1], stmn[len][r]);
  };
  auto getmx = [&](int l, int r) {
    int len = std::__lg(r - l + 1);
    return std::max(stmx[len][l + (1 << len) - 1], stmx[len][r]);
  };

  for (int i = n; i >= 1; i--) {
    // L[i]  = max{p[j]|p[j]<p[i]\land j<i}
    // R[i]  = min{p[j]|p[j]>p[i]\land j<i}
    // L2[i] = min{j|p[j]<p[i]\land j>i}
    // R2[i] = min{j|p[j]>p[i]\land j>i}

    // initialize

    int _l = i, _r = n, l = n + 1, r = n + 1;
    while (_l <= _r) {
      int mid = (_l + _r) / 2;
      if (getmn(i, mid) < p[i])
        _r = mid - 1, l = mid;
      else
        _l = mid + 1;
    }
    _l = i, _r = n;
    // int r = i;
    while (_l <= _r) {
      int mid = (_l + _r) / 2;
      if (getmx(i, mid) > p[i])
        _r = mid - 1, r = mid;
      else
        _l = mid + 1;
    }

    // std::cerr << std::format("rangeApplyX({},{},{})\n", i, l - 1, p[i]);
    tr.rangeApply(i, l, Tag{p[i], -1});
    // std::cerr << std::format("rangeApplyY({},{},{})\n", i, r - 1, p[i]);
    tr.rangeApply(i, r, Tag{-1, p[i]});
    // tr.modify()

    _l = i, _r = n;
    int u = -1, v = -1;
    while (_l <= _r) {
      int mid = (_l + _r) / 2;
      if (getmn(i, mid) > L[i])
        _l = mid + 1, u = mid;
      else
        _r = mid - 1;
    }
    _l = i, _r = n;
    while (_l <= _r) {
      int mid = (_l + _r) / 2;
      if (getmx(i, mid) < R[i])
        _l = mid + 1, v = mid;
      else
        _r = mid - 1;
    }

    // if (u == -1) {
    //   u = i;
    // }
    // if (v == -1) {
    //   v = i;
    // }
    // std::cerr << "u=" << u << ',' << "v=" << v << '\n';
    u = std::min(u, v);

    // std::cerr << u << ' ' << i << '\n';
    // for (int j = i; j <= n; j++) {
    //   std::cerr << std::format("x({},{})={}\n", i, j,
    //                            tr.rangeQuery(i, j + 1).x);
    //   std::cerr << std::format("y({},{})={}\n", i, j,
    //                            tr.rangeQuery(i, j + 1).y);
    // }

    auto info = tr.rangeQuery(i, u + 1);
    // std::cerr << "sx=" << info.sx << ',' << "sy=" << info.sy << ',' << "sxy=" << info.sxy << '\n';
    ans -= (u - i + 1) * R[i] * L[i];
    ans += info.sx * R[i];
    ans += info.sy * L[i];
    ans -= info.sxy;
    // st.insert(p[i]);
  }
  // std::cerr << '\n';
  std::cout << ans << '\n';
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