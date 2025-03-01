#include <bits/stdc++.h>
#define N 100001
#define int long long
using namespace std;

int a[N], mod;

struct Seg {
  Seg() {
    mul = 1;
  }
  int v, mul, add;
} segs[N << 2];

void pushup(int rt) {
  segs[rt].v = (segs[rt << 1].v + segs[rt << 1 | 1].v) % mod;
}

void pushdown(int s, int t, int rt) {
  int ls = rt << 1, rs = rt << 1 | 1, mid = s + (t - s >> 1);

  segs[ls].v = segs[rt].mul * segs[ls].v % mod + segs[rt].add * (mid - s + 1) % mod;
  segs[ls].v %= mod;
  segs[rs].v = segs[rt].mul * segs[rs].v % mod + segs[rt].add * (t - mid) % mod;
  segs[rs].v %= mod;

  segs[ls].mul = segs[rt].mul * segs[ls].mul % mod;
  segs[rs].mul = segs[rt].mul * segs[rs].mul % mod;
  segs[ls].add = (segs[ls].add * segs[rt].mul % mod + segs[rt].add) % mod;
  segs[rs].add = (segs[rs].add * segs[rt].mul % mod + segs[rt].add) % mod;

  segs[rt].add = 0, segs[rt].mul = 1;
}

void build(int s, int t, int rt) {
  if (s == t) {
    segs[rt].v = a[s];
    return;
  }
  int mid = s + (t - s >> 1);
  build(s, mid, rt << 1);
  build(mid + 1, t, rt << 1 | 1);
  pushup(rt);
}

void mul(int l, int r, int s, int t, int rt, int k) {
  if (l <= s && t <= r) {
    segs[rt].mul = segs[rt].mul * k % mod;
    segs[rt].add = segs[rt].add * k % mod;
    segs[rt].v = segs[rt].v * k % mod;
    return;
  }
  pushdown(s, t, rt);
  int mid = s + (t - s >> 1);
  if (l <= mid) mul(l, r, s, mid, rt << 1, k);
  if (r > mid) mul(l, r, mid + 1, t, rt << 1 | 1, k);
  pushup(rt);
}

void add(int l, int r, int s, int t, int rt, int k) {
  if (l <= s && t <= r) {
    segs[rt].add = (segs[rt].add + k) % mod;
    segs[rt].v = (segs[rt].v + k * (t - s + 1)) % mod;
    return;
  }
  pushdown(s, t, rt);
  int mid = s + (t - s >> 1);
  if (l <= mid) add(l, r, s, mid, rt << 1, k);
  if (r > mid) add(l, r, mid + 1, t, rt << 1 | 1, k);
  pushup(rt);
}

int query(int l, int r, int s, int t, int rt) {
  if (l <= s && t <= r) {
    return segs[rt].v;
  }
  pushdown(s, t, rt);
  int mid = s + (t - s >> 1), ans = 0;
  if (l <= mid) ans += query(l, r, s, mid, rt << 1);
  if (r > mid) ans += query(l, r, mid + 1, t, rt << 1 | 1);
  return ans % mod;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  int n, q;;
  cin >> n >> q >> mod;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  build(1, n, 1);
  for (int i = 0; i < q; i++) {
    int op, l, r, k;
    cin >> op >> l >> r;
    if (op == 1) {
      cin >> k;
      mul(l, r, 1, n, 1, k);
    } else if (op == 2) {
      cin >> k;
      add(l, r, 1, n, 1, k);
    } else {
      cout << query(l, r, 1, n, 1) << '\n';
    }
  }
  return 0;
}