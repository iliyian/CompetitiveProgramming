// date: 2024-07-15 16:50:29
// tag: 线段树维护复杂信息

#include <bits/stdc++.h>
#define int long long
#define lc p << 1
#define rc p << 1 | 1
// using namespace std;

constexpr int N = 5e4;

struct Seg {
  int len, maxlen = 0, llen = 0, rlen = 0;
} seg[(N + 5) << 2];

std::vector<int> laz((N + 5) << 2, -1);

Seg merge(const Seg &x, const Seg &y) {
  return {
    x.len + y.len,
    std::max({x.maxlen, y.maxlen, x.rlen + y.llen}),
    x.llen == x.len ? x.len + y.llen : x.llen,
    y.rlen == y.len ? x.rlen + y.len : y.rlen
  };
}

void pushup(int p) {
  seg[p] = merge(seg[lc], seg[rc]);
}

void build(int l, int r, int p) {
  int len = r - l + 1;
  seg[p] = {len, len, len, len};
  if (l == r) {
    return;
  }
  int mid = (l + r) / 2;
  build(l, mid, lc);
  build(mid + 1, r, rc);
}

void exec(int p, int val) {
  laz[p] = val;
  int tlen = seg[p].len * (val ^ 1);
  seg[p] = {seg[p].len, tlen, tlen, tlen};
}

void pushdown(int p) {
  if (laz[p] != -1) {
    exec(lc, laz[p]);
    exec(rc, laz[p]);
  }
  laz[p] = -1;
}

void modify(int l, int r, int s, int t, int p, int val) {
  if (l <= s && t <= r) {
    exec(p, val);
    return;
  }
  pushdown(p);
  int mid = (s + t) / 2;
  if (l <= mid) modify(l, r, s, mid, lc, val);
  if (r > mid) modify(l, r, mid + 1, t, rc, val);
  pushup(p);
}

int query(int l, int r, int p, int req) {
  if (l == r) return l;
  int mid = (l + r) / 2;
  pushdown(p);
  if (seg[lc].maxlen >= req) return query(l, mid, lc, req);
  if (seg[lc].rlen + seg[rc].llen >= req) return mid - seg[lc].rlen + 1;
  return query(mid + 1, r, rc, req);
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  int n, m;
  std::cin >> n >> m;

  build(1, n, 1);
  for (int i = 1; i <= m; i++) {
    int op, x, y;
    std::cin >> op;
    if (op == 1) {
      std::cin >> x;
      int l = 0;
      if (seg[1].maxlen >= x) {
        l = query(1, n, 1, x);
        if (l) {
          modify(l, l + x - 1, 1, n, 1, 1);
        }
      }
      std::cout << l << '\n';
    } else {
      std::cin >> x >> y;
      modify(x, x + y - 1, 1, n, 1, 0);
    }
  }

  return 0;
}