// date: 2024-03-21 13:54:16
// tag: 扫描线

#include <bits/stdc++.h>
#define int long long
#define lc p << 1
#define rc p << 1 | 1
#define N 200005 // 这边建议开大点好
using namespace std;

struct Seg {
  int l, r, sum;
} seg[N << 3];
int exi[N << 3], v[N << 1];

struct Lin {
  int x, y1, y2, f;
  bool operator < (const Lin &b) const {
    return x < b.x;
  }
} lin[N << 1];

void pushup(int p) {  
  assert(p <= (N << 3));
  if (exi[p]) {
    seg[p].sum = seg[p].r - seg[p].l;
  } else {
    seg[p].sum = seg[lc].sum + seg[rc].sum;
  }
}

void build(int l, int r, int p) {
  assert(p <= (N << 3));
  seg[p] = {v[l], v[r]};
  if (l == r - 1) { // 这也就导致 l != r 恒成立
    return;
  }
  int mid = (l + r) / 2;
  build(l, mid, lc);
  build(mid, r, rc); // 注意相邻线段有交点
  pushup(p);
}

void update(int l, int r, int f, int p) {
  assert(p <= (N << 3));
  if (l == seg[p].l && r == seg[p].r) {
    exi[p] += f;
  } else {
    if (l < seg[lc].r) update(l, min(seg[lc].r, r), f, lc);
    if (r > seg[rc].l) update(max(seg[rc].l, l), r, f, rc);
  }
  pushup(p);
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    lin[i] = {x1, y1, y2, 1};
    lin[i + n] = {x2, y1, y2, -1};
    v[i + 1] = y1, v[i + n + 1] = y2;
  }
  // 线段树节点的索引从1开始
  sort(v + 1, v + n * 2 + 1);
  sort(lin, lin + n * 2);
  build(1, n * 2, 1);
  int ans = 0;
  for (int i = 0; i < n * 2 - 1; i++) {
    update(lin[i].y1, lin[i].y2, lin[i].f, 1);
    ans += (lin[i + 1].x - lin[i].x) * seg[1].sum;
  }
  cout << ans << '\n';

  return 0;
}