#include <bits/stdc++.h>
// #include <chrono>
// #define int long long

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
  int w = 0;
  void apply(const Tag &t) & {
    w += t.w;
  }
};
 
struct Info { 
  int mx = 0;
  void apply(const Tag &t) & {
    mx += t.w;
  }
};
 
Info operator+(const Info &a, const Info &b) {
  return Info{std::max(a.mx, b.mx)};
}

constexpr int N = 1e4;

// #define DEBUG 1  // 调试开关
struct IO {
#define MAXSIZE (1 << 20)
#define isdigit(x) (x >= '0' && x <= '9')
  char buf[MAXSIZE], *p1, *p2;
  char pbuf[MAXSIZE], *pp;
#if DEBUG
#else
  IO() : p1(buf), p2(buf), pp(pbuf) {}

  ~IO() { fwrite(pbuf, 1, pp - pbuf, stdout); }
#endif
  char gc() {
#if DEBUG  // 调试，可显示字符
    return getchar();
#endif
    if (p1 == p2) p2 = (p1 = buf) + fread(buf, 1, MAXSIZE, stdin);
    return p1 == p2 ? ' ' : *p1++;
  }

  void read(int &x) {
    bool neg = false;
    x = 0;
    char ch = gc();
    for (; !isdigit(ch); ch = gc())
      if (ch == '-') neg = true;
    if (neg)
      for (; isdigit(ch); ch = gc()) x = x * 10 + ('0' - ch);
    else
      for (; isdigit(ch); ch = gc()) x = x * 10 + (ch - '0');
  }

  void read(char *s) {
    char ch = gc();
    for (; isspace(ch); ch = gc());
    for (; !isspace(ch); ch = gc()) *s++ = ch;
    *s = 0;
  }

  void read(char &c) { for (c = gc(); isspace(c); c = gc()); }

  void push(const char &c) {
#if DEBUG  // 调试，可显示字符
    putchar(c);
#else
    if (pp - pbuf == MAXSIZE) fwrite(pbuf, 1, MAXSIZE, stdout), pp = pbuf;
    *pp++ = c;
#endif
  }

  void write(int x) {
    bool neg = false;
    if (x < 0) {
      neg = true;
      push('-');
    }
    static int sta[40];
    int top = 0;
    do {
      sta[top++] = x % 10;
      x /= 10;
    } while (x);
    if (neg)
      while (top) push('0' - sta[--top]);
    else
      while (top) push('0' + sta[--top]);
  }

  void write(int x, char lastChar) { write(x), push(lastChar); }
} io;

void solve() {
  int n, k;
  // std::cin >> n >> k;
  io.read(n);
  io.read(k);
  std::vector<std::vector<std::pair<int, int>>> a(n + 1);
  // std::unordered_map<std::pair<int, int>, int> mp;
  std::map<std::pair<int, int>, int> mp;
  for (int i = 1; i <= n; i++) {
    int x, y, v;
    // std::cin >> x >> y >> v;
    io.read(x);
    io.read(y);
    io.read(v);
    mp[{x, y}] += v;
    // mp[x * n + y] += v;
    // a[x].push_back({y, v});
  }
  for (auto &[k, v] : mp) {
    auto &[x, y] = k;
    // int x = k / n, y = k % n;
    // if (y == 0) y = n;
    a[x].push_back({y, v});
  }
  int ans = 0;
  LazySegmentTree<Info, Tag> tr(n + 1);
  auto work = [&] {
    for (int w = 1; w <= k; w++) {
      // for (int w : fac[k]) {
      // std::cout << "q=" << query(n) << '\n';
      // int h = k / w;
      int h = k / w;
      // if (h == 0)
      //   continue;
      if ((w + 1) * h <= k)
        continue;

      // std::cerr << w << ' ' << h << '\n';
      for (int i = 1; i <= n; i++) {
        if (i - w >= 1) {
          for (auto &[y, v] : a[i - w]) {
            tr.rangeApply(y, std::min(n, y + h - 1) + 1, Tag{-v});
          }
        }
        for (auto &[y, v] : a[i]) {
          tr.rangeApply(y, std::min(n, y + h - 1) + 1, Tag{v});
        }
        if (i >= w) {
          ans = std::max(ans, tr.rangeQuery(h, n + 1).mx);
          // ans = std::max(ans, tr.info[1].mx);
        }
      }
      for (int i = n + 1; i - w <= n; i++) {
        if (i - w >= 1) {
          for (auto &[y, v] : a[i - w]) {
            tr.rangeApply(y, std::min(n, y + h - 1) + 1, Tag{-v});
          }
        }
      }
    }
  };
  work();

  // std::cout << ans << '\n';
  io.write(ans, '\n');
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  // auto start = std::chrono::high_resolution_clock::now();

  int t = 1;
  // std::cin >> t;
  io.read(t);

  while (t--) {
    solve();
  }
  
  // auto end = std::chrono::high_resolution_clock::now();
  // std::cerr << std::chrono::duration<double, std::milli>(end - start) << '\n';
  return 0;
}