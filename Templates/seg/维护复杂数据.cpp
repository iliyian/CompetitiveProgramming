// date: 2024-05-23 15:03:18
// tag: 线段树维护复杂数据
// 注意以c++20标准在oj上编译不过

#include <bits/stdc++.h>
#define int long long
#define N ((int)1e5)
#define lc p << 1
#define rc p << 1 | 1
using namespace std;

struct Seg {
  int cnt0, cnt1, maxlen0, maxlen1, llen0, llen1, rlen0, rlen1;
} seg[(N + 1) << 2];

vector<int> a(N + 1), len((N + 1) << 2);
vector<array<int, 2>> tag((N + 1) << 2);

Seg merge(const Seg &p, const Seg &q) {
  return Seg{
    p.cnt0 + q.cnt0,
    p.cnt1 + q.cnt1,
    max({p.maxlen0, q.maxlen0, p.rlen0 + q.llen0}),
    max({p.maxlen1, q.maxlen1, p.rlen1 + q.llen1}),
    !p.cnt1 ? p.maxlen0 + q.llen0 : p.llen0,
    !p.cnt0 ? p.maxlen1 + q.llen1 : p.llen1,
    !q.cnt1 ? q.maxlen0 + p.rlen0 : q.rlen0,
    !q.cnt0 ? q.maxlen1 + p.rlen1 : q.rlen1,
  };
}

void exec(int p, int typ) {
  auto tmp = seg[p];
  if (typ == 0) {
    tag[p] = {0, 0};
    seg[p] = {len[p], 0, len[p], 0, len[p], 0, len[p], 0};
  }
  if (typ == 1) {
    tag[p] = {1, 0};
    seg[p] = {0, len[p], 0, len[p], 0, len[p], 0, len[p]};
  }
  if (typ == 2) {
    tag[p][1] ^= 1;
    seg[p] = {tmp.cnt1, tmp.cnt0, tmp.maxlen1, tmp.maxlen0, tmp.llen1, tmp.llen0, tmp.rlen1, tmp.rlen0};
  }
}

void pushdown(int p) {
  if (tag[p][0] != -1) {
    exec(lc, tag[p][0]);
    exec(rc, tag[p][0]);
  }
  if (tag[p][1]) {
    exec(lc, 2);
    exec(rc, 2);
  }
  tag[p] = {-1, 0};
}

void build(int l, int r, int p) {
  len[p] = r - l + 1;
  tag[p] = {-1, 0};
  if (l == r) {
    seg[p] = {!a[l], a[l], !a[l], a[l], !a[l], a[l], !a[l], a[l]};
    return;
  }
  int mid = (l + r) / 2;
  build(l, mid, lc);
  build(mid + 1, r, rc);
  seg[p] = merge(seg[lc], seg[rc]);
}

void modify(int l, int r, int s, int t, int p, int c) {
  if (l <= s && t <= r) {
    exec(p, c);
    return;
  };
  int mid = (s + t) / 2;
  pushdown(p);
  if (l <= mid) modify(l, r, s, mid, lc, c);
  if (r > mid) modify(l, r, mid + 1, t, rc, c);
  seg[p] = merge(seg[lc], seg[rc]);
}

Seg query(int l, int r, int s, int t, int p) {
  if (t < l || r < s) return Seg{};
  if (l <= s && t <= r) {
    return seg[p];
  }
  int mid = (s + t) / 2;
  pushdown(p);
  return merge(query(l, r, s, mid, lc), query(l, r, mid + 1, t, rc));
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  build(1, n, 1);
  for (int i = 1; i <= m; i++) {
    int op, l, r;
    cin >> op >> l >> r;
    l++, r++;
    if (op < 3) {
      modify(l, r, 1, n, 1, op);
    } else {
      auto ans = query(l, r, 1, n, 1);
      if (op == 3) {
        cout << ans.cnt1 << '\n';
      } else {
        cout << ans.maxlen1 << '\n';
      }
    }
  }

  return 0;
}