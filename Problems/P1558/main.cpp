#include <bits/stdc++.h>
#define N 100001
using namespace std;

int color[N << 3], cnt[N << 3], laz[N << 3];

void pushup(int p) {
  color[p] = color[p << 1] | color[p << 1 | 1];
}

void build(int s, int t, int p) {
  if (s == t) {
    color[p] = 1;
    return;
  }
  int mid = s + (t - s >> 1);
  build(s, mid, p << 1);
  build(mid + 1, t, p << 1 | 1);
  pushup(p);
}

void pushdown(int p) {
  if (!laz[p]) return;
  int ls = p << 1, rs = p << 1 | 1;
  color[ls] = color[rs] = laz[p];
  laz[ls] = laz[rs] = laz[p];
  laz[p] = 0;
}

void update(int l, int r, int s, int t, int p, int c) {
  if (l <= s && t <= r) {
    pushdown(p);
    color[p] = 1 << c - 1;
    laz[p] = 1 << c - 1;
    return;
  }
  int mid = s + (t - s >> 1);
  pushdown(p);
  if (l <= mid) update(l, r, s, mid, p << 1, c);
  if (r > mid) update(l, r, mid + 1, t, p << 1 | 1, c);
  pushup(p);
}

int query(int l, int r, int s, int t, int p) {
  if (l <= s && t <= r) {
    return color[p];
  }
  int mid = s + (t - s >> 1), ans = 0;
  pushdown(p);
  if (l <= mid) ans |= query(l, r, s, mid, p << 1);
  if (r > mid) ans |= query(l, r, mid + 1, t, p << 1 | 1);
  return ans;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  int L, T, O;
  cin >> L >> T >> O;
  build(1, L, 1);
  for (int i = 0; i < O; i++) {
    int x, y, c;
    char op;
    cin >> op >> x >> y;
    if (x > y) swap(x, y);
    if (op == 'C') {
      cin >> c;
      update(x, y, 1, L, 1, c);
    } else {
      int ans = query(x, y, 1, L, 1), cnt = 0;
      while (ans) cnt += ans & 1, ans >>= 1;
      cout << cnt << '\n';
    }
  }
  return 0;
}