/*

LLLLLLLLLLL             IIIIIIIIIIYYYYYYY       YYYYYYYIIIIIIIIII               AAA               NNNNNNNN        NNNNNNNN
L:::::::::L             I::::::::IY:::::Y       Y:::::YI::::::::I              A:::A              N:::::::N       N::::::N
L:::::::::L             I::::::::IY:::::Y       Y:::::YI::::::::I             A:::::A             N::::::::N      N::::::N
LL:::::::LL             II::::::IIY::::::Y     Y::::::YII::::::II            A:::::::A            N:::::::::N     N::::::N
  L:::::L                 I::::I  YYY:::::Y   Y:::::YYY  I::::I             A:::::::::A           N::::::::::N    N::::::N
  L:::::L                 I::::I     Y:::::Y Y:::::Y     I::::I            A:::::A:::::A          N:::::::::::N   N::::::N
  L:::::L                 I::::I      Y:::::Y:::::Y      I::::I           A:::::A A:::::A         N:::::::N::::N  N::::::N
  L:::::L                 I::::I       Y:::::::::Y       I::::I          A:::::A   A:::::A        N::::::N N::::N N::::::N
  L:::::L                 I::::I        Y:::::::Y        I::::I         A:::::A     A:::::A       N::::::N  N::::N:::::::N
  L:::::L                 I::::I         Y:::::Y         I::::I        A:::::AAAAAAAAA:::::A      N::::::N   N:::::::::::N
  L:::::L                 I::::I         Y:::::Y         I::::I       A:::::::::::::::::::::A     N::::::N    N::::::::::N
  L:::::L         LLLLLL  I::::I         Y:::::Y         I::::I      A:::::AAAAAAAAAAAAA:::::A    N::::::N     N:::::::::N
LL:::::::LLLLLLLLL:::::LII::::::II       Y:::::Y       II::::::II   A:::::A             A:::::A   N::::::N      N::::::::N
L::::::::::::::::::::::LI::::::::I    YYYY:::::YYYY    I::::::::I  A:::::A               A:::::A  N::::::N       N:::::::N
L::::::::::::::::::::::LI::::::::I    Y:::::::::::Y    I::::::::I A:::::A                 A:::::A N::::::N        N::::::N
LLLLLLLLLLLLLLLLLLLLLLLLIIIIIIIIII    YYYYYYYYYYYYY    IIIIIIIIIIAAAAAAA                   AAAAAAANNNNNNNN         NNNNNNN

 * 
 * ==============================================================================
 * @Author : iliyian
 * @File   : C.cpp
 * @Time   : 2025-10-21 04:38:27
 * ==============================================================================
*/

// 确实是一种珂朵莉树的思想吧？

#include <bits/stdc++.h>
#define int long long

struct Node {
  int l, r;
  mutable int v;
  Node(int l, int r = 0, int v = 0) : l(l), r(r), v(v) {}
  bool operator < (const Node &b) const {
    return l < b.l;
  }
};

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
        push(p, r - l);
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
        push(p, r - l);
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
        push(p, r - l);
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
  int val = 0;
  void apply(const Tag &t, int len) & {
    val += t.val;
  }
};
 
struct Info {
  int mx = 0, idx = 0;
  void apply(const Tag &t, int len) & {
    mx += t.val;
  }
};
 
Info operator+(const Info &a, const Info &b) {
  Info c;
  if (a.mx == b.mx) {
    if (a.idx < b.idx) {
      return a;
    }
    return b;
  } else {
    if (a.mx < b.mx) {
      return b;
    }
    return a;
  }
}

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::set<Node> s;
  std::vector<int> a(n + 1), cnt(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    cnt[a[i]]++;
    s.insert(Node(i, i, a[i]));
  }
  std::vector<Info> info(n * 2 + 1);
  for (int i = 0; i <= n * 2; i++) {
    info[i] = {i > n ? 0 : cnt[i], i};
  }
  LazySegmentTree<Info, Tag> lsgt(info);
  auto split = [&](int pos) {
    auto it = s.lower_bound(Node(pos));
    if (it != s.end() && it->l == pos) {
      return it;
    }
    it--;
    if (it->r < pos) {
      return s.end();
    }
    int l = it->l, r = it->r, v = it->v;
    s.erase(it);
    s.insert(Node(l, pos - 1, v));
    return s.insert(Node(pos, r, v + pos - l)).first;
  };
  std::cout << lsgt.info[1].idx << ' ' << lsgt.info[1].mx << '\n';
  while (m--) {
    int l, r, x;
    std::cin >> l >> r >> x;
    auto itr = split(r + 1), itl = split(l); 
    for (auto it = itl; it != itr; it++) {
      lsgt.rangeApply(it->v, it->v + it->r - it->l + 1, Tag{-1});
    }
    s.erase(itl, itr);
    s.insert(Node(l, r, x));
    lsgt.rangeApply(x, x + r - l + 1, Tag{1});
    std::cout << lsgt.info[1].idx << ' ' << lsgt.info[1].mx << '\n';
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
