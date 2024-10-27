#include <bits/stdc++.h>
#define lc p << 1
#define rc p << 1 | 1
#define mid (s + t) / 2

constexpr int N = 1e5;

struct Seg {
  int len = 0, cnt0 = 0, cnt1 = 0;
  int llen0 = 0, llen1 = 0, rlen0 = 0, rlen1 = 0, maxlen0 = 0, maxlen1 = 0;
};

std::vector<Seg> seg(N << 2);
std::vector<int> val(N << 2, -1), rev(N << 2);

std::vector<int> a(N + 1);
int n, m;

Seg merge(const Seg &x, const Seg &y) {
  if (!x.len) return y;
  if (!y.len) return x;
  return Seg{
    x.len + y.len,
    x.cnt0 + y.cnt0, x.cnt1 + y.cnt1,
    x.llen0 == x.len ? x.llen0 + y.llen0 : x.llen0,
    x.llen1 == x.len ? x.llen1 + y.llen1 : x.llen1,
    y.rlen0 == y.len ? y.rlen0 + x.rlen0 : y.rlen0,
    y.rlen1 == y.len ? y.rlen1 + x.rlen1 : y.rlen1,
    std::max({x.maxlen0, y.maxlen0, x.rlen0 + y.llen0}),
    std::max({x.maxlen1, y.maxlen1, x.rlen1 + y.llen1}),
  };
}

void P(int p, int typ) {
  if (typ == 0) {
    seg[p] = {seg[p].len, seg[p].len, 0, seg[p].len, 0, seg[p].len, 0, seg[p].len, 0};
    val[p] = 0;
  } else if (typ == 1) {
    seg[p] = {seg[p].len, 0, seg[p].len, 0, seg[p].len, 0, seg[p].len, 0, seg[p].len};
    val[p] = 1;
  } else if (typ == 2) {
    seg[p] = {
      seg[p].len,
      seg[p].cnt1, seg[p].cnt0, 
      seg[p].llen1, seg[p].llen0, 
      seg[p].rlen1, seg[p].rlen0, 
      seg[p].maxlen1, seg[p].maxlen0
    };
    rev[p] ^= 1;
    if (val[p] != -1) {
      val[p] ^= 1;
    }
  }
}

void pull(int p) {
  seg[p] = merge(seg[lc], seg[rc]);
}

void pushdown(int p) {
  if (val[p] != -1) {
    P(lc, val[p]), P(rc, val[p]);
    val[p] = -1, rev[p] = 0;
  }
  if (rev[p]) {
    P(lc, 2), P(rc, 2);
    rev[p] ^= 1;
  }
}

void modify(int l, int r, int s, int t, int p, int c) {
  if (l > t || r < s) return;
  if (l <= s && t <= r) {
    P(p, c);
    return;
  }
  pushdown(p);
  modify(l, r, s, mid, lc, c);
  modify(l, r, mid + 1, t, rc, c);
  pull(p);
}

void build(int s, int t, int p) {
  seg[p].len = t - s + 1;
  if (s == t) {
    seg[p] = {1, !a[s], a[s], !a[s], a[s], !a[s], a[s], !a[s], a[s]};
    return;
  }
  build(s, mid, lc);
  build(mid + 1, t, rc);
  pull(p);
}

Seg query(int l, int r, int s, int t, int p) {
  if (l > t || r < s) return {};
  if (l <= s && t <= r) {
    return seg[p];
  }
  pushdown(p);
  return merge(query(l, r, s, mid, lc), query(l, r, mid + 1, t, rc));
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  freopen("E.in", "r", stdin);
  std::cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  build(1, n, 1);
  for (int i = 1; i <= m; i++) {
    int op, l, r;
    std::cin >> op >> l >> r;
    l++, r++;
    if (op == 0) {
      modify(l, r, 1, n, 1, 0);
    } else if (op == 1) {
      modify(l, r, 1, n, 1, 1);
    } else if (op == 2) {
      modify(l, r, 1, n, 1, 2);
    } else if (op == 3) {
      std::cout << query(l, r, 1, n, 1).cnt1 << '\n';
    } else {
      std::cout << query(l, r, 1, n, 1).maxlen1 << '\n';
    }
  }
  return 0;
}