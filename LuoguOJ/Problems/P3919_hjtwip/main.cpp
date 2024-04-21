#include <bits/stdc++.h>
#define lc hjt[ver].l
#define rc hjt[ver].r
#define N 100005
using namespace std;

struct HJT {
  int l, r, v;
} hjt[N << 5];

int a[N], top = 0;

int clone(int x) {
  hjt[++top] = hjt[x];
  return top;
}

int build(int s, int t, int ver) {
  ver = ++top;
  if (s == t) {
    hjt[ver].v = a[s];
    return top;
  }
  int mid = s + (t - s >> 1);
  build(s, mid, lc);
  build(mid + 1, t, rc);
}

int update(int ver, int s, int t, int p, int c) {
  ver = clone(ver);
  if (s == t) {
    hjt[ver].v = c;
    return;
  }
  int mid = s + (t - s >> 1);
  if (p <= mid) update(ver, s, mid, p, c);
  if (p > mid) update(ver, mid + 1, t, p, c);
  return ver;
}

int query(int ver, int s, int t, int p) {
  if (s == t) return hjt[ver].v;
  int mid = s + (t - s >> 1);
  if (p <= mid) return query(lc, s, mid, p);
  if (p > mid) return query(rc, mid + 1, t, p);
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  int n, m;
  cin >> n >> m;
  build(1, n, 0);
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  for (int i = 0; i < m; i++) {
    int ver, op, loc, x;
    cin >> ver >> op >> loc;
    if (op == 1) {
      cin >> x;

    }
  }
}