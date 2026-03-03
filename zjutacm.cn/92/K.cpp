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
 * @Author  : iliyian
 * @File    : K.cpp
 * @Time    : 2025-12-21 00:44:23
 * @Comment : 
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
  Info(char c) {
    l = r = c;
    cnt[c - 'a']++;
  }
  char l = -1, r = -1;
  int cnt[26] {};
  bool ordered = true;
};

Info operator+(const Info &a, const Info &b) {
  if (a.l == -1) return b;
  if (b.l == -1) return a;
  Info c;
  c.l = a.l, c.r = b.r;
  c.ordered = (a.ordered && b.ordered && a.r <= b.l);
  for (int i = 0; i < 26; i++) {
    c.cnt[i] = a.cnt[i] + b.cnt[i];
  }
  return c;
}

void check(auto &s, auto &t) {
  return;
  if (s != t) {
    std::cout << "gg\n";
    assert(false);
  }
}

void solve() {
  int n, q, cnt[26] {};
  std::string s;
  std::cin >> n >> s >> q;
  std::vector<Info> a(n);
  for (int i = 0; i < n; i++) {
    a[i] = Info(s[i]);
    cnt[s[i] - 'a']++;
  }
  SegmentTree<Info> tr(a);
  while (q--) {
    int op;
    std::cin >> op;
    if (op == 1) {
      int x;
      char c;
      std::cin >> x >> c;
      x--;
      cnt[s[x] - 'a']--;
      s[x] = c;
      cnt[s[x] - 'a']++;
      tr.modify(x, Info(c));
    } else {
      int l, r;
      std::cin >> l >> r;
      l--, r--;
      auto info = tr.rangeQuery(l, r + 1);
      std::string ans;
      // std::cin >> ans;
      if (!info.ordered) {
        std::cout << "No\n";
        check(ans, "No");
        continue;
      }
      if (info.l == info.r) {
        std::cout << "Yes\n";
        check(ans, "Yes");
        continue;
      }
      int sum = 0;
      bool flag = true;
      for (int i = info.l - 'a' + 1; i <= info.r - 'a' - 1; i++) {
        sum += cnt[i];
        if (info.cnt[i] != cnt[i]) {
          std::cout << "No\n";
          check(ans, "No");
          flag = false;
          break;
        }
      }
      if (!flag) continue;
      if (info.cnt[info.l - 'a'] + info.cnt[info.r - 'a'] + sum == r - l + 1) {
        std::cout << "Yes\n";
        check(ans, "Yes");
      } else {
        std::cout << "No\n";
        check(ans, "No");
      }
    }
  }
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  // freopen("d.in", "r", stdin);

  int t = 1;
  // std::cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}
