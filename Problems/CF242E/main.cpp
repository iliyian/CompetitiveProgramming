// date: 2024-04-09 20:06:02
// tag: 线段树区间异或与区间和，顺便pushdown真的只要处理children就行了啊

#include <bits/stdc++.h>
#define int long long
#define N 100005
#define lc p << 1
#define rc p << 1 | 1
using namespace std;

int sm[21][N << 2], a[N], rev[21][N << 2];

void pushdown(int s, int t, int p, int x) {
  if (rev[x][p]) {
    int mid = (s + t) / 2;
    rev[x][lc] ^= 1, rev[x][rc] ^= 1;
    sm[x][lc] = mid - s + 1 - sm[x][lc], sm[x][rc] = t - mid - sm[x][rc];
    rev[x][p] = 0;
  }
}

void pushup(int p, int x) {
  sm[x][p] = sm[x][lc] + sm[x][rc];
}

void build(int l, int r, int p, int x) {
  if (l == r) {
    sm[x][p] = a[l] >> x & 1;
    return;
  }
  int mid = (l + r) / 2;
  build(l, mid, lc, x);
  build(mid + 1, r, rc, x);
  pushup(p, x);
}

void flip(int l, int r, int s, int t, int p, int x) {
  if (l <= s && t <= r) {
    sm[x][p] = t - s + 1 - sm[x][p];
    rev[x][p] ^= 1;
    return;
  }
  int mid = (s + t) / 2;
  pushdown(s, t, p, x);
  if (l <= mid) flip(l, r, s, mid, lc, x);
  if (r > mid) flip(l, r, mid + 1, t, rc, x);
  pushup(p, x);
}

int querycnt(int l, int r, int s, int t, int p, int x) {
  if (l <= s && t <= r) return sm[x][p];
  int mid = (s + t) / 2, ans = 0;
  pushdown(s, t, p, x);
  if (l <= mid) ans += querycnt(l, r, s, mid, lc, x);
  if (r > mid) ans += querycnt(l, r, mid + 1, t, rc, x);
  return ans;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i <= 20; i++) {
    build(1, n, 1, i);
  }
  int q;
  cin >> q;
  for (int _ = 1; _ <= q; _++) {
    int op, l, r, x;
    cin >> op >> l >> r;
    if (op == 1) {
      int ans = 0;
      for (int i = 0; i <= 20; i++) {
        ans += querycnt(l, r, 1, n, 1, i) * (1 << i);
      }
      cout << ans << '\n';
    } else {
      cin >> x;
      for (int i = 0; i <= 20; i++) {
        if (x >> i & 1) {
          flip(l, r, 1, n, 1, i);
        }
      }
    }
  }

  return 0;
}