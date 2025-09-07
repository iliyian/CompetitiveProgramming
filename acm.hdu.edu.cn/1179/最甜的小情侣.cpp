#include <bits/stdc++.h>
#include <clocale>
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
  int f[4][4] {};
  int len = 0, mx = 0;
  Info() {};
  Info(int x) : len(1) {
    f[1][1] = mx = x;
  }
};

Info operator+(const Info &a, const Info &b) {
  if (a.len == 0) return b;
  if (b.len == 0) return a;
  Info c;
  c.len = a.len + b.len;
  for (int i = 0; i <= std::min<int>(3, a.len); i++) {
    for (int j = 0; j <= std::min<int>(3, b.len); j++) {
      if (i == a.len && j == b.len) {
        if (i + j < 4) {
          c.f[i + j][i + j] = a.f[i][i] + b.f[j][j];
        }
        continue;
      }
      if (i == a.len) {
        for (int k = 0; k <= std::min(3 - i, b.len); k++) {
          c.f[i + k][j] = a.f[i][i] + b.f[k][j];
        }
        continue;
      }
      if (j == b.len) {
        for (int k = 0; k <= std::min(3 - j, a.len); k++) {
          c.f[i][j + k] = b.f[j][j] + a.f[i][k];
        }
        continue;
      }
      int mx = 0;
      for (int k = 3; k >= 0; k--) {
        mx = std::max(mx, b.f[3 - k][j]);
        c.f[i][j] = std::max(c.f[i][j], a.f[i][k] + mx);
      }
    }
  }
  return c;
}

void solve() {
  int n, q;
  std::cin >> n >> q;
  std::vector<Info> a(n + 1);
  for (int i = 1; i <= n; i++) {
    int x;
    std::cin >> x;
    a[i] = Info(x);
  }
  SegmentTree<Info> tr(a);
  auto query = [&]() {
    int ans = 0;
    for (int i = 0; i <= std::min<int>(3, n); i++) {
      for (int j = 0; j <= std::min<int>(3, n); j++) {
        if (i + j <= 3) {
          ans = std::max(ans, tr.info[1].f[i][j]);
        }
      }
    }
    return ans;
  };
  std::cout << query() << '\n';
  for (int i = 1; i <= q; i++) {
    int x, v;
    std::cin >> x >> v;
    tr.modify(x, Info(v));
    std::cout << query() << '\n';
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