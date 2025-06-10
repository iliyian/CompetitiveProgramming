// date: 2025-05-29 18:19:53
// tag: 比较少见的树剖套线段树

#include <bits/stdc++.h>
#include <chrono>
#define int long long

template <class Info, class Tag> struct LSGT {
#define l(p) (p << 1)
#define r(p) (p << 1 | 1)
  int n;
  std::vector<Info> info;
  std::vector<Tag> tag;
  LSGT() {}
  LSGT(int _n, Info _v = Info()) { init(_n, _v); }
  template <class T> LSGT(std::vector<T> _init) { init(_init); }
  void init(int _n, Info _v = Info()) { init(std::vector(_n, _v)); }
  template <class T> void init(std::vector<T> _init) {
    n = _init.size();
    info.assign(4 << std::__lg(n), Info());
    tag.assign(4 << std::__lg(n), Tag());
    auto build = [&](auto self, int p, int l, int r) {
      if (r - l == 1) {
        info[p] = _init[l];
        return;
      }
      int m = l + r >> 1;
      self(self, l(p), l, m);
      self(self, r(p), m, r);
      pull(p);
    };
    build(build, 1, 0, n);
  }
  void pull(int p) { info[p] = info[l(p)] + info[r(p)]; }
  void apply(int p, const Tag &v, int len) {
    info[p].apply(v, len);
    tag[p].apply(v);
  }
  void push(int p, int len) {
    apply(l(p), tag[p], len / 2);
    apply(r(p), tag[p], len - len / 2);
    tag[p] = Tag();
  }
  void modify(int p, int l, int r, int x, const Info &v) {
    if (r - l == 1) {
      info[p] = v;
      return;
    }
    int m = l + r >> 1;
    push(p, r - l);
    if (x < m) {
      modify(l(p), l, m, x, v);
    } else {
      modify(r(p), m, r, x, v);
    }
    pull(p);
  }
  void modify(int p, const Info &v) { modify(1, 0, n, p, v); }
  Info query(int p, int l, int r, int x, int y) {
    if (l >= y or r <= x) {
      return Info();
    }
    if (l >= x and r <= y) {
      return info[p];
    }
    int m = l + r >> 1;
    push(p, r - l);
    return query(l(p), l, m, x, y) + query(r(p), m, r, x, y);
  }
  Info query(int l, int r) { return query(1, 0, n, l, r); }
  void Apply(int p, int l, int r, int x, int y, const Tag &v) {
    if (l >= y or r <= x) {
      return;
    }
    if (l >= x and r <= y) {
      apply(p, v, r - l);
      return;
    }
    int m = l + r >> 1;
    push(p, r - l);
    Apply(l(p), l, m, x, y, v);
    Apply(r(p), m, r, x, y, v);
    pull(p);
  }
  void Apply(int l, int r, const Tag &v) { return Apply(1, 0, n, l, r, v); }
#undef l
#undef r
};

struct Tag {
  int v = 0;
  Tag(int v = 0) : v(v) {};
  void apply(const Tag &t) { v += t.v; }
};
struct Info {
  int sum = 0;
  void apply(const Tag &t, int len) { sum += t.v; }
};
Info operator+(const Info &a, const Info &b) { return Info{a.sum + b.sum}; }

struct HLD {
  int n;
  std::vector<int> siz, top, dep, parent, in, out, seq, inleaf;
  std::vector<std::vector<int>> adj;
  int cur, leafcnt;

  HLD() {}
  HLD(int n) { init(n); }
  void init(int n) {
    this->n = n;
    this->leafcnt = 0;
    siz.resize(n);
    inleaf.resize(n);
    top.resize(n);
    dep.resize(n);
    parent.resize(n);
    in.resize(n);
    out.resize(n);
    seq.resize(n);
    cur = 0;
    adj.assign(n, {});
  }
  void addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  void work(int root = 0) {
    top[root] = root;
    dep[root] = 0;
    parent[root] = -1;
    dfs1(root);
    dfs2(root);
  }
  void dfs1(int u) {
    if (adj[u].size() == 1) {
      inleaf[u]++;
      leafcnt++;
    }
    if (parent[u] != -1) {
      adj[u].erase(std::find(adj[u].begin(), adj[u].end(), parent[u]));
    }

    siz[u] = 1;
    for (auto &v : adj[u]) {
      parent[v] = u;
      dep[v] = dep[u] + 1;
      dfs1(v);
      siz[u] += siz[v];
      inleaf[u] += inleaf[v];
      if (siz[v] > siz[adj[u][0]]) {
        std::swap(v, adj[u][0]);
      }
    }
  }
  void dfs2(int u) {
    in[u] = cur++;
    seq[in[u]] = u;
    for (auto v : adj[u]) {
      top[v] = v == adj[u][0] ? top[u] : v;
      dfs2(v);
    }
    out[u] = cur;
  }
  int lca(int u, int v) {
    while (top[u] != top[v]) {
      if (dep[top[u]] > dep[top[v]]) {
        u = parent[top[u]];
      } else {
        v = parent[top[v]];
      }
    }
    return dep[u] < dep[v] ? u : v;
  }

  int dist(int u, int v) { return dep[u] + dep[v] - 2 * dep[lca(u, v)]; }

  int jump(int u, int k) {
    if (dep[u] < k) {
      return -1;
    }

    int d = dep[u] - k;

    while (dep[top[u]] > d) {
      u = parent[top[u]];
    }

    return seq[in[u] - dep[u] + d];
  }

  bool isAncester(int u, int v) { return in[u] <= in[v] && in[v] < out[u]; }

  int rootedParent(int u, int v) {
    std::swap(u, v);
    if (u == v) {
      return u;
    }
    if (!isAncester(u, v)) {
      return parent[u];
    }
    auto it = std::upper_bound(adj[u].begin(), adj[u].end(), v,
                               [&](int x, int y) { return in[x] < in[y]; }) -
              1;
    return *it;
  }

  int rootedSize(int u, int v) {
    if (u == v) {
      return n;
    }
    if (!isAncester(v, u)) {
      return siz[v];
    }
    return n - siz[rootedParent(u, v)];
  }

  int rootedLca(int a, int b, int c) {
    return lca(a, b) ^ lca(b, c) ^ lca(c, a);
  }
};

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

  bool blank(char ch) {
    return ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t';
  }

  template <class T>
  void read(T &x) {
    double tmp = 1;
    bool sign = false;
    x = 0;
    char ch = gc();
    for (; !isdigit(ch); ch = gc())
      if (ch == '-') sign = 1;
    for (; isdigit(ch); ch = gc()) x = x * 10 + (ch - '0');
    if (ch == '.')
      for (ch = gc(); isdigit(ch); ch = gc())
        tmp /= 10.0, x += tmp * (ch - '0');
    if (sign) x = -x;
  }

  void read(char *s) {
    char ch = gc();
    for (; blank(ch); ch = gc());
    for (; !blank(ch); ch = gc()) *s++ = ch;
    *s = 0;
  }

  void read(char &c) { for (c = gc(); blank(c); c = gc()); }

  void push(const char &c) {
#if DEBUG  // 调试，可显示字符
    putchar(c);
#else
    if (pp - pbuf == MAXSIZE) fwrite(pbuf, 1, MAXSIZE, stdout), pp = pbuf;
    *pp++ = c;
#endif
  }

  template <class T>
  void write(T x) {
    if (x < 0) x = -x, push('-');  // 负数输出
    static T sta[35];
    T top = 0;
    do {
      sta[top++] = x % 10, x /= 10;
    } while (x);
    while (top) push(sta[--top] + '0');
  }

  template <class T>
  void write(T x, char lastChar) {
    write(x), push(lastChar);
  }
} io;

void solve() {
  // auto start = std::chrono::steady_clock::now();
  int n, q;
  // std::cin >> n >> q;
  io.read(n), io.read(q);
  HLD hld(n);
  int tot = -1;
  for (int i = 0; i < n - 1; i++) {
    int x, y;
    // std::cin >> x >> y;
    io.read(x);
    io.read(y);
    x--, y--;
    hld.addEdge(x, y);
  }
  hld.work(0);
  LSGT<Info, Tag> h_seg(n), out_seg(n);
  std::vector<int> l_sum(n);
  // for (int i = 0; i < n; i++) {
  //   std::cerr << inleaf[i] << " \n"[i == n - 1];
  // }
  // for (int i = 0; i < n; i++) {
  //   std::cerr << hld.in[i] << " \n"[i == n - 1];
  // }
  // for (int i = 0; i < n; i++) {
  //   std::cerr << isleaf(i) << " \n"[i == n - 1];
  // }
  std::vector<int> self(n), h_c(n);
  for (int i = 0; i < n; i++) {
    h_c[i] = hld.adj[i].empty() ? 0 : hld.leafcnt - hld.inleaf[hld.adj[i][0]];
  }
  // auto end = std::chrono::steady_clock::now();
  // std::cerr << std::chrono::duration<double, std::milli>(end - start) << '\n';
  while (q--) {
    int op;
    // std::cin >> op;
    io.read(op);
    if (op == 1) {
      int u, w;
      // std::cin >> u >> w;
      io.read(u), io.read(w);
      u--;
      Tag t(w), nt(-w);

      out_seg.Apply(0, n, t);
      out_seg.Apply(hld.in[u], hld.in[u] + 1, nt);
      self[u] += w * hld.leafcnt;
      while (u != -1) { // 不断处理 [pa[top[u]],pa[u]]
        int l = hld.parent[hld.top[u]];
        if (l != -1) {
          // l_seg.Apply(l, l + 1, Tag(w * (leafcnt - inleaf[hld.top[u]])));
          l_sum[l] += w * (hld.leafcnt - hld.inleaf[hld.top[u]]);
          // l = hld.in[l];
          out_seg.Apply(hld.in[l], hld.in[l] + 1, nt);
        }
        int p = hld.parent[u], tp = hld.top[u];
        if (p != -1) {
          p = hld.in[p], tp = hld.in[tp];
          h_seg.Apply(tp, p + 1, t);
          out_seg.Apply(tp, p + 1, nt);
        }
        u = l;
      }
    } else {
      int u;
      // std::cin >> u;
      io.read(u);
      u--;
      int inu = hld.in[u];
      // auto l_sum = l_seg.query(inu, inu + 1);
      auto h_sum = h_seg.query(inu, inu + 1);
      auto out_sum = out_seg.query(inu, inu + 1);
      // std::cerr << out_sum.sum << ' ' << l_sum.sum << ' ' << h_sum.sum << ' '
      // << self[u] << '\n';
      // std::cout << self[u] + out_sum.sum * hld.inleaf[u] + l_sum[u] + h_sum.sum * h_c[u] << '\n';
      io.write(self[u] + out_sum.sum * hld.inleaf[u] + l_sum[u] + h_sum.sum * h_c[u], '\n');
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