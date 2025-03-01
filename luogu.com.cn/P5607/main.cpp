// date: 2024-09-28 12:27:16
// tag: 线段树套线性基

#include <bits/stdc++.h>
#define lc p << 1
#define rc p << 1 | 1
#define mid (s + t) / 2

constexpr int N = 5e4;
std::vector<int> a(N + 2), b(N + 2);

struct Seg {
  std::array<int, 32> d;
  void insert(int x) {
    for (int i = 30; i >= 0; i--) {
      if (x >> i & 1) {
        if (d[i]) {
          x ^= d[i];
        } else {
          d[i] = x;
          return;
        }
      }
    }
  }
  Seg operator + (const Seg &b) const {
    Seg ans = *this;
    for (int i = 30; i >= 0; i--) {
      ans.insert(b.d[i]);
    }
    return ans;
  }
};
std::vector<Seg> seg(N << 2);
std::vector<int> d(N << 2);

void pull(int p) {
  seg[p] = seg[lc] + seg[rc];
  d[p] = d[lc] ^ d[rc];
}

void build(int s, int t, int p) {
  if (s == t) {
    seg[p].insert(b[s]);
    d[p] = b[s];
    return;
  }
  build(s, mid, lc);
  build(mid + 1, t, rc);
  pull(p);
}

void modify(int x, int s, int t, int p, int c) {
  if (x > t || x < s) return;
  if (x == s && x == t) {
    d[p] ^= c;
    for (int i = 30; i >= 0; i--) {
      seg[p].d[i] = 0;
    }
    seg[p].insert(d[p]);
    return;
  }
  modify(x, s, mid, lc, c);
  modify(x, mid + 1, t, rc, c);
  pull(p);
}

Seg query(int l, int r, int s, int t, int p) {
  if (l > t || r < s || l > r) return {};
  if (l <= s && t <= r) return seg[p];
  return query(l, r, s, mid, lc) + query(l, r, mid + 1, t, rc);
}

int queryxor(int l, int r, int s, int t, int p) {
  if (l > t || r < s) return 0;
  if (l <= s && t <= r) return d[p];
  return queryxor(l, r, s, mid, lc) ^ queryxor(l, r, mid + 1, t, rc);
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("main.in", "r", stdin);

  int n, m;
  std::cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    b[i] = a[i] ^ a[i - 1];
  }
  build(1, n, 1);
  for (int i = 1; i <= m; i++) {
    int op, l, r, x;
    std::cin >> op >> l >> r >> x;
    if (op == 1) {
      modify(l, 1, n, 1, x);
      modify(r + 1, 1, n, 1, x);
    } else {
      auto s = query(l + 1, r, 1, n, 1);
      s.insert(queryxor(1, l, 1, n, 1));
      for (int j = 30; j >= 0; j--) {
        if ((x ^ s.d[j]) > x) {
          x ^= s.d[j];
        }
      }
      std::cout << x << '\n';
    }
  }
  return 0;
}