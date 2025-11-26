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
 * @File   : 209_R_34_F_子串数量.cpp
 * @Time   : 2025-10-27 15:48:10
 * ==============================================================================
*/

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
  Info() {};
  Info(int x) {
    len = 1;
    if (x == -1) {
      cnt = 1;
      ans = 1;
      rdif = -1, rpos = 1;
    } else if (x == 0) {
      lcnt = 1, rdif = 0;
    } else {
      rdif = 1;
    }
  }
  int ans = 0;
  int cnt = 0, len = 0, lcnt = 0, rdif = 1, rpos = 0;
};

Info operator+(const Info &a, const Info &b) {
  if (a.len == 0) return b;
  if (b.len == 0) return a;
  Info c;
  c.ans = a.ans + b.ans;
  c.len = a.len + b.len;
  c.cnt = a.cnt + b.cnt;
  if (b.rdif == -1) {
    c.cnt += a.lcnt;
    c.ans += a.lcnt * (b.len - b.rpos + 1);
  }
  c.ans += a.cnt * b.len;
  c.lcnt = b.lcnt;
  if (b.lcnt == b.len) {
    c.lcnt += a.lcnt;
  }
  c.rdif = a.rdif;
  c.rpos = a.rpos;
  if (a.rdif == 0) {
    c.rdif = b.rdif;
    c.rpos = b.rpos + a.len;
  }
  return c;
}

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::string s, t;
  std::cin >> s >> t;
  s = '#' + s, t = '#' + t;
  std::vector<Info> a(n + 1);
  for (int i = 1; i <= n; i++) {
    a[i] = (s[i] < t[i] ? -1 : s[i] == t[i] ? 0 : 1);
  }
  SegmentTree<Info> tr(a);
  // for (int l = 1; l <= n; l++) {
  //   for (int r = l; r <= n; r++) {
  //     std::cout << "l=" << l << ",r=" << r << '\n';
  //     auto info = tr.rangeQuery(l, r + 1);
  //     std::cout << info.ans << ' ' << info.cnt << ' ' << info.lcnt << ' ' << info.rdif << '\n';
  //   }
  // }
  while (m--) {
    int op;
    std::cin >> op;
    if (op == 1) {
      int i;
      char c;
      std::cin >> i >> c;
      s[i] = c;
      tr.modify(i, (s[i] < t[i] ? -1 : s[i] == t[i] ? 0 : 1));
    } else if (op == 2) {
      int i;
      char c;
      std::cin >> i >> c;
      t[i] = c;
      tr.modify(i, (s[i] < t[i] ? -1 : s[i] == t[i] ? 0 : 1));
    } else {
      int l, r;
      std::cin >> l >> r;
      std::cout << tr.rangeQuery(l, r + 1).ans << '\n';
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
