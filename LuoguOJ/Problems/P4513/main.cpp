// date: 2024/02/05 22:29:56
// tag: wa#01: query写错了，即使只在左或右一个区间也不能直接返回当前p的左或右的node
// 只有当前区间完全包含于查询区间，查询区间完全包含了当前节点区间，
// 当前节点区间才可以直接返回，不用任何调用
// 其他都不行
// 线段树简单应用

#include <bits/stdc++.h>
#define N 500005
#define inf 0x3f3f3f3f
#define lc p << 1
#define rc p << 1 | 1
using namespace std;

struct Node {
  int maxl, maxr, sum, ans;
} nodes[N << 2];

int a[N], n, m;

void pushup(Node &p, const Node &l, const Node &r) {
  p.sum = l.sum + r.sum;
  p.maxl = max(l.maxl, l.sum + r.maxl);
  p.maxr = max(r.maxr, l.maxr + r.sum);
  p.ans = max(max(l.ans, r.ans), l.maxr + r.maxl);
}

void build(int l, int r, int p) {
  if (l == r) {
    nodes[p] = {a[l], a[l], a[l], a[l]};
    return;
  }
  int mid = l + (r - l >> 1);
  build(l, mid, lc);
  build(mid + 1, r, rc);
  pushup(nodes[p], nodes[lc], nodes[rc]);
}


Node query(int l, int r, int s, int t, int p) {
  if (l <= s && t <= r) return nodes[p];
  int mid = s + (t - s >> 1);
  if (r <= mid) return query(l, r, s, mid, lc);
  else if (l > mid) return query(l, r, mid + 1, t, rc);
  else {
    Node rt, ln = query(l, r, s, mid, lc),
      rn = query(l, r, mid + 1, t, rc);
    pushup(rt, ln, rn);
    return rt;
  }
}

void modify(int s, int t, int p, int x, int c) {
  if (s == t && s == x) {
    nodes[p] = {c, c, c, c};
    return;
  }
  int mid = s + (t - s >> 1);
  if (x <= mid) modify(s, mid, lc, x, c);
  else modify(mid + 1, t, rc, x, c);
  pushup(nodes[p], nodes[lc], nodes[rc]);
}

void solve() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  build(1, n, 1);
  for (int i = 0; i < m; i++) {
    int k;
    cin >> k;
    if (k == 1) {
      int a, b;
      cin >> a >> b;
      if (a > b) swap(a, b);
      cout << query(a, b, 1, n, 1).ans << '\n';
    } else {
      int p, s;
      cin >> p >> s;
      modify(1, n, 1, p, s);
    }
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);
  // int _; cin >> _;
  int _ = 1;
  while (_--) solve();
}