#include <bits/stdc++.h>
#define N 1000001
#define inf 0x3f3f3f3f3f3f3f3f
// 切切有八个3f
#define int long long
using namespace std;

int a[N], d[N << 2];

struct Node {
  int t1, t2;
  Node() {
    t1 = inf;
  }
} b[N << 2];

void pushup(int p) {
  d[p] = max(d[p << 1], d[p << 1 | 1]);
}

void modify(int p, int c, int op) {
  if (op == 1) {
    d[p] = b[p].t1 = c;
    b[p].t2 = 0;
  } else {
    d[p] += c;
    if (b[p].t1 != inf) {
      b[p].t1 += c;
    } else {
      b[p].t2 += c;
    }
  }
}

void pushdown(int p) {
  if (b[p].t1 != inf) {
    modify(p << 1, b[p].t1, 1);
    modify(p << 1 | 1, b[p].t1, 1);
    b[p].t1 = inf;
  } else if (b[p].t2) {
    modify(p << 1, b[p].t2, 2);
    modify(p << 1 | 1, b[p].t2, 2);
    b[p].t2 = 0;
  }
}

void update(int l, int r, int s, int t, int p, int c, int op) {
  if (l <= s && t <= r) {
    modify(p, c, op);
    return;
  }
  int mid = s + (t - s >> 1);
  pushdown(p);
  if (l <= mid) update(l, r, s, mid, p << 1, c, op);
  if (r > mid) update(l, r, mid + 1, t, p << 1 | 1, c, op);
  pushup(p);
}

void build(int s, int t, int p) {
  if (s == t) {
    d[p] = a[s];
    return;
  }
  int mid = s + (t - s >> 1);
  build(s, mid, p << 1);
  build(mid + 1, t, p << 1 | 1);
  pushup(p);
}

int query(int l, int r, int s, int t, int p) {
  if (l <= s && t <= r) return d[p];
  int mid = s + (t - s >> 1), ans = -inf;
  pushdown(p);
  if (l <= mid) ans = max(ans, query(l, r, s, mid, p << 1));
  if (r > mid) ans = max(ans, query(l, r, mid + 1, t, p << 1 | 1));
  return ans;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  int n, q;
  cin >> n >> q;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  build(1, n, 1);
  for (int i = 0; i < q; i++) {
    int op, l, r, c;
    cin >> op >> l >> r;
    if (op != 3) {
      cin >> c;
      update(l, r, 1, n, 1, c, op);
    } else {
      cout << query(l, r, 1, n, 1) << '\n';
    }
  }
  return 0;
}