// date: 2024-09-21 00:27:49
// tag: 线段树区间加等差数列，区间和

#include <bits/stdc++.h>
#define int long long
#define mid (s + t) / 2
#define lc p << 1
#define rc p << 1 | 1
using namespace std;

constexpr int N = 3e5;

int n, m, q;

struct Seg {
  int val, dis, sum, len;
};

std::vector<Seg> seg(N << 2);
std::vector<std::array<int, 2>> tag(N << 2);
std::set<std::pair<int, int>> se;

Seg merge(const Seg &x, const Seg &y) {
  return Seg{
    x.val,
    x.dis + y.dis,
    x.sum + y.sum,
    x.len + y.len,
  };
}

void pull(int p) {
  seg[p] = merge(seg[lc], seg[rc]);
}

void build(int s, int t, int p) {
  seg[p].len = t - s + 1;
  tag[p] = {0, -1};
  if (s == t) {
    auto R = se.lower_bound({s, 0});
    auto L = std::prev(R);
    if (R->first == s) {
      seg[p] = {0, 0, 0, 1};
    } else {
      seg[p] = {L->second, R->first - s, L->second * (R->first - s), 1};
    }
    return;
  };
  build(s, mid, lc);
  build(mid + 1, t, rc);
  pull(p);
}

void P(int p, int c, int typ) {
  if (typ == 1) {
    tag[p][0] += c;
    seg[p].dis += c * seg[p].len;
  }
  if (typ == 2) {
    tag[p][1] = c;
    seg[p].val = c;
  }
  seg[p].sum = seg[p].dis * seg[p].val;
}

void push(int p) {
  if (tag[p][0]) {
    P(lc, tag[p][0], 1), P(rc, tag[p][0], 1);
  }
  if (tag[p][1] != -1) {
    P(lc, tag[p][1], 2), P(rc, tag[p][1], 2);
  }
  tag[p] = {0, -1};
}

void add(int l, int r, int s, int t, int p, int c) {
  if (l > t || r < s) return;
  if (l <= s && t <= r) {
    P(p, c, 1);
    return;
  }
  push(p);
  add(l, r, s, mid, lc, c);
  add(l, r, mid + 1, t, rc, c);
  pull(p);
}

void modify(int l, int r, int s, int t, int p, int c) {
  if (l > t || r < s) return;
  if (l <= s && t <= r) {
    P(p, c, 2);
    return;
  }
  push(p);
  modify(l, r, s, mid, lc, c);
  modify(l, r, mid + 1, t, rc, c);
  pull(p);
}

int query(int l, int r, int s, int t, int p) {
  if (l > t || r < s) return 0;
  if (l <= s && t <= r) return seg[p].sum;
  push(p);
  return query(l, r, s, mid, lc) + query(l, r, mid + 1, t, rc);
}

void reset(int s, int t, int p, int x) {
  if (x < s || x > t) return;
  if (s == t && s == x) {
    seg[p] = {0, 0, 0, 1};
    return;
  }
  push(p);
  reset(s, mid, lc, x);
  reset(mid + 1, t, rc, x);
  pull(p);
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  freopen("B.in", "r", stdin);

  std::cin >> n >> m >> q;
  std::vector<int> pos(m + 1);
  for (int i = 1; i <= m; i++) {
    std::cin >> pos[i];
  }
  for (int i = 1; i <= m; i++) {
    int v;
    std::cin >> v;
    se.insert({pos[i], v});
  }
  build(1, n, 1);
  while (q--) {
    int op, x, y;
    std::cin >> op >> x >> y;
    if (op == 1) {
      auto R = se.lower_bound({x, y});
      auto L = std::prev(R);
      add(L->first + 1, x - 1, 1, n, 1, -(R->first - x));
      modify(x + 1, R->first - 1, 1, n, 1, y);
      reset(1, n, 1, x);
      se.insert({x, y});
    } else {
      std::cout << query(x, y, 1, n, 1) << '\n';
    }
  }
  return 0;
}