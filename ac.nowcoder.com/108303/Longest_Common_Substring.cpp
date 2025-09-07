// date: 2025-08-03 15:24:19
// tag: SAM处理子串，然后区间修单点查线段树，利用endpos性质

#include <bits/stdc++.h>
#define int long long

using i64 = long long;

struct SAM {
    static constexpr int ALPHABET_SIZE = 26;
    struct Node {
        int len;
        int link;
        std::array<int, ALPHABET_SIZE> next;
        Node() : len{}, link{}, next{} {}
    };
    std::vector<Node> t;
    SAM() {
        init();
    }
    void init() {
        t.assign(2, Node());
        t[0].next.fill(1);
        t[0].len = -1;
    }
    int newNode() {
        t.emplace_back();
        return t.size() - 1;
    }
    int extend(int p, int c) {
        if (t[p].next[c]) {
            int q = t[p].next[c];
            if (t[q].len == t[p].len + 1) {
                return q;
            }
            int r = newNode();
            t[r].len = t[p].len + 1;
            t[r].link = t[q].link;
            t[r].next = t[q].next;
            t[q].link = r;
            while (t[p].next[c] == q) {
                t[p].next[c] = r;
                p = t[p].link;
            }
            return r;
        }
        int cur = newNode();
        t[cur].len = t[p].len + 1;
        while (!t[p].next[c]) {
            t[p].next[c] = cur;
            p = t[p].link;
        }
        t[cur].link = extend(p, c);
        return cur;
    }
    // int extend(int p, char c, char offset = 'a') {
    //     return extend(p, c - offset);
    // }
    
    int next(int p, int x) {
        return t[p].next[x];
    }
    
    // int next(int p, char c, char offset = 'a') {
    //     return next(p, c - 'a');
    // }
    
    int link(int p) {
        return t[p].link;
    }
    
    int len(int p) {
        return t[p].len;
    }
    
    int size() {
        return t.size();
    }
};

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
      int m = (l + r) >> 1;
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
    int m = (l + r) >> 1;
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
    int m = (l + r) >> 1;
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
    int m = (l + r) >> 1;
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
  int val;
  Tag() : val(LLONG_MIN / 3) {}
  Tag(int val) : val(val) {}
  void apply(const Tag &t) {
    val = std::max(val, t.val);
  }
};

struct Info {
  int mx;
  Info() : mx(LLONG_MIN / 3){}
  Info(int mx) : mx(mx) {}
  void apply(const Tag &t, int len) {
    mx = std::max(mx, t.val);
  }
};

Info operator+(const Info &a, const Info &b) {
  Info c;
  c.mx = std::max(a.mx, b.mx);
  return c;
}

void solve() {
  int n, q;
  std::cin >> n >> q;
  std::string str;
  std::cin >> str;
  SAM sam;
  int p = 1;
  std::vector<int> mn(n * 2 + 1, LLONG_MAX / 3), mx(n * 2 + 1, LLONG_MIN / 3);
  for (int i = 0; i < n; i++) {
    p = sam.extend(p, str[i] - 'a');
    mn[p] = mx[p] = i;
  }
  int m = sam.size();
  std::vector<int> P(m);
  std::iota(P.begin(), P.end(), 0);
  std::ranges::sort(P, [&](auto x, auto y) {
    return sam.len(x) > sam.len(y);
  });
  for (int u : P) {
    int v = sam.link(u);
    if (v > 1) {
      mn[v] = std::min(mn[v], mn[u]);
      mx[v] = std::max(mx[v], mx[u]);
    }
  }
  std::vector<std::vector<std::array<int, 2>>> ask(n);
  for (int i = 0; i < q; i++) {
    int l, r;
    std::cin >> l >> r;
    l--, r--;
    ask[l].push_back({r, i});
  }
  std::vector<std::vector<int>> v(n);
  for (int i = 2; i < m; i++) {
    v[mn[i]].push_back(i);
  }
  std::vector<int> ans(q);
  LSGT<Info, Tag> T1(n), T2(n);
  for (int i = 0; i < n; i++) {
    for (int u : v[i]) {
      int v = mx[u] - sam.len(u) + 1;
      T1.Apply(0, v + 1, sam.len(u));
      T2.Apply(v + 1, n, Tag(mx[u]));
    }
    for (auto [r, idx] : ask[i]) {
      ans[idx] = std::max(T1.query(r, r + 1).mx, T2.query(r, r + 1).mx - r + 1);
    }
  }
  for (int i : ans) {
    std::cout << i << '\n';
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