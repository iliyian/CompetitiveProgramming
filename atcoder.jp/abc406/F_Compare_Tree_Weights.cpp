#include <bits/stdc++.h>
using namespace std;
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
        info[p] = {init_[l]};
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

struct Info {
  int sum = 0;
};

Info operator+(const Info &a, const Info &b) { return Info{a.sum + b.sum}; }

constexpr int N = 1 << 21;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n, 1);
  std::vector<std::vector<int>> g(n);
  std::vector<std::pair<int, int>> e(n + 1);
  for (int i = 1; i <= n - 1; i++) {
    int x, y;
    std::cin >> x >> y;
    x--, y--;
    g[x].push_back(y);
    g[y].push_back(x);
    e[i] = {x, y};
  }
  std::vector<int> dfn(n), siz(n), rnk(n);
  int tot = -1, sum = n;
  auto dfs = [&](auto self, int u, int p) -> void {
    dfn[u] = ++tot;
    rnk[tot] = u;
    siz[u] = 1;
    for (int v : g[u]) {
      if (v != p) {
        self(self, v, u);
        siz[u] += siz[v];
      }
    }
  };
  dfs(dfs, 0, -1);
  SegmentTree<Info> seg(a);
  int q;
  std::cin >> q;
  while (q--) {
    int op;
    std::cin >> op;
    if (op == 1) {
      int x, w;
      std::cin >> x >> w;
      x--;
      a[x] += w;
      sum += w;
      seg.modify(dfn[x], {a[x]});
    } else {
      int idx;
      std::cin >> idx;
      auto [x, y] = e[idx];
      if (dfn[x] < dfn[y])
        std::swap(x, y);
      std::cout << std::abs(sum - 2 * seg.rangeQuery(dfn[x], dfn[x] + siz[x]).sum)
                << '\n';
    }
  }
}

signed main() {
  solve();
  return 0;
}