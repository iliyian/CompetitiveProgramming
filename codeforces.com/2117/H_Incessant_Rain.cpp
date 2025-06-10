// date: 2025-06-10 18:08:12
// tag: 好，是线段树！首先得想到可以转换成单点修区间最大连续子数组，然后要想到转换成值域上离线处理。

#include <bits/stdc++.h>
#define int long long

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
  int mx = 0, lmx = 0, rmx = 0, sum = 0;
};

Info operator+(const Info &a, const Info &b) {
  Info c;
  c.mx = std::max({a.mx, b.mx, a.rmx + b.lmx});
  c.lmx = std::max({a.lmx, a.sum + b.lmx}),
  c.rmx = std::max({b.rmx, a.rmx + b.sum}),
  c.sum = a.sum + b.sum;
  return c;
}

void solve() {
  int n, q;
  std::cin >> n >> q;
  std::vector<int> a(n);
  // std::vector<std::vector<int>> pos(n);
  std::vector<std::set<int>> pos(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
    a[i]--;
    // pos[a[i]].push_back(i);
    pos[a[i]].insert(i);
  }
  auto b = a;
  std::vector<std::vector<std::array<int, 3>>> op(n);
  for (int i = 0; i < q; i++) {
    int idx, x;
    std::cin >> idx >> x;
    idx--;
    x--;
    op[b[idx]].push_back({idx, i, -1});
    b[idx] = x;
    op[b[idx]].push_back({idx, i, 1});
  }
  Info posi{1, 1, 1, 1}, neg{0, 0, 0, -1};
  SegmentTree<Info> seg(n, neg);
  std::vector<std::vector<std::pair<int, int>>> sop(q);
  std::multiset<int> ms;
  std::vector<int> val(n);
  for (int i = 0; i < n; i++) {
    std::set<int> s;
    for (int j : pos[i]) {
      s.insert(j);
      seg.modify(j, posi);
    }
    ms.insert(val[i] = seg.rangeQuery(0, n).mx / 2);
    for (auto [j, p, k] : op[i]) {
      if (k == 1) {
        seg.modify(j, posi);
        pos[i].insert(j);
      } else {
        seg.modify(j, neg);
        pos[i].erase(j);
      }
      sop[p].push_back({i, seg.rangeQuery(0, n).mx / 2});
    }
    for (auto j : pos[i]) {
      seg.modify(j, neg);
    }
  }
  for (int i = 0; i < q; i++) {
    for (auto [j, mx] : sop[i]) {
      ms.erase(ms.find(val[j]));
      val[j] = mx;
      ms.insert(mx);
    }
    std::cout << *ms.rbegin() << ' ';
  }
  std::cout << '\n';
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