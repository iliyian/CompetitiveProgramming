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
  Tag() {};
  void apply(const Tag &t) {

  }
};
struct Info {
  void apply(const Tag &t, int len) {

  }
};
Info operator+(const Info &a, const Info &b) {
  Info c;
  
  return c;
}
