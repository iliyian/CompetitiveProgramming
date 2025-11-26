// date: 2025-09-27 23:04:46
// tag: 又是一个oi-wiki没有的算法属于是

#include <algorithm>
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
  int v[2] {}, cnt[2] {};
  Info() {};
  Info(int x) {
    v[0] = x, cnt[0] = 1;
  }
};

Info operator+(Info a, Info b) {
  Info c = a;
  for (int i = 0; i < 2; i++) {
    if (b.cnt[i]) {
      bool f = false;
      int mn = b.cnt[i];
      for (int j = 0; j < 2; j++) {
        if (c.v[j] == b.v[i]) {
          c.cnt[j] += b.cnt[i];
          goto end;
        }
      }
      for (int j = 0; j < 2; j++) {
        mn = std::min(mn, c.cnt[j]);
        if (!c.cnt[j]) {
          c.v[j] = b.v[i];
          c.cnt[j] = b.cnt[i];
          goto end;
        }
      }
      for (int j = 0; j < 2; j++) {
        c.cnt[j] -= mn;
      }
      b.cnt[i] -= mn;
      if (b.cnt[i]) {
        for (int j = 0; j < 2; j++) {
          if (!c.cnt[j]) {
            c.v[j] = b.v[i];
            c.cnt[j] = b.cnt[i];
            goto end;
          }
        }
      }
    }
    end:;
  }
  return c;
}

void solve() {
  int n, q;
  std::cin >> n >> q;
  std::vector<int> a(n + 1);
  std::map<int, std::vector<int>> v;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    v[a[i]].push_back(i);
  }
  auto get = [&](int x, int l, int r) {
    return std::ranges::upper_bound(v[x], r) - std::ranges::lower_bound(v[x], l);
  };
  SegmentTree<Info> tr(a);
  while (q--) {
    int l, r;
    std::cin >> l >> r;
    auto info = tr.rangeQuery(l, r + 1);
    std::vector<int> ans;
    int threshold = (r - l + 1) / 3;
    if (info.cnt[0] && get(info.v[0], l, r) > threshold) { // necessary
      ans.push_back(info.v[0]);
    }
    if (info.cnt[1] && get(info.v[1], l, r) > threshold) {
      ans.push_back(info.v[1]);
    }
    if (ans.size() == 0) {
      std::cout << -1 << '\n';
    } else {
      std::ranges::sort(ans);
      for (auto v : ans) {
        std::cout << v << ' ';
      }
      std::cout << '\n';
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