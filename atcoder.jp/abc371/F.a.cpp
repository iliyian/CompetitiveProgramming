#include <bits/stdc++.h>
using namespace std;
#define int long long
int x[200005], ans;
struct node {
  int l, r, mx, sum, tg;
} t[800005];
void pushup(int p) {
  t[p].mx = max(t[p * 2].mx, t[p * 2 + 1].mx);
  t[p].sum = t[p * 2].sum + t[p * 2 + 1].sum;
}
void pushdown(int p) {
  if (t[p].tg == -1e18)
    return;
  int tmp = t[p].tg;
  t[p].tg = -1e18;
  t[p * 2].tg = t[p * 2 + 1].tg = tmp;
  t[p * 2].mx = t[p * 2 + 1].mx = tmp;
  t[p * 2].sum = tmp * (t[p * 2].r - t[p * 2].l + 1);
  t[p * 2 + 1].sum = tmp * (t[p * 2 + 1].r - t[p * 2 + 1].l + 1);
}
void build(int p, int l, int r) {
  t[p].l = l, t[p].r = r, t[p].tg = -1e18;
  if (l == r) {
    t[p].mx = t[p].sum = x[l];
    return;
  }
  int mid = (l + r) / 2;
  build(p * 2, l, mid);
  build(p * 2 + 1, mid + 1, r);
  pushup(p);
}
void setv(int p, int l, int r, int v) {
  if (l <= t[p].l && t[p].r <= r) {
    t[p].sum = (t[p].r - t[p].l + 1) * v;
    t[p].mx = t[p].tg = v;
    return;
  }
  pushdown(p);
  int mid = (t[p].l + t[p].r) / 2;
  if (mid >= l)
    setv(p * 2, l, r, v);
  if (mid < r)
    setv(p * 2 + 1, l, r, v);
  pushup(p);
}
int querymx(int p, int l, int r) {
  if (l <= t[p].l && t[p].r <= r) {
    return t[p].mx;
  }
  pushdown(p);
  int mid = (t[p].l + t[p].r) / 2, mx = -1e18;
  if (mid >= l)
    mx = max(mx, querymx(p * 2, l, r));
  if (mid < r)
    mx = max(mx, querymx(p * 2 + 1, l, r));
  return mx;
}
int query(int p, int l, int r) {
  if (l <= t[p].l && t[p].r <= r) {
    return t[p].sum;
  }
  pushdown(p);
  int mid = (t[p].l + t[p].r) / 2, sum = 0;
  if (mid >= l)
    sum += query(p * 2, l, r);
  if (mid < r)
    sum += query(p * 2 + 1, l, r);
  return sum;
}
signed main() {
  freopen("F.in", "r", stdin);
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> x[i];
    x[i] -= i;
  }
  build(1, 1, n);
  int q;
  cin >> q;
  for (int i = 1; i <= q; i++) {
    int t, g;
    cin >> t >> g;
    int tpos = query(1, t, t);
    g -= t;
    if (tpos == g)
      continue;
    if (tpos > g) {
      int l = 1, r = n, pos = t;
      while (l <= r) {
        int mid = (l + r) / 2;
        if (querymx(1, 1, mid) <= g) { // 通过二分找到要修改的 l 和 r。
          l = mid + 1;
        } else {
          r = mid - 1;
          pos = mid;
        }
      }
      ans += std::abs(query(1, pos, t) - (g) * (t - pos + 1));
      setv(1, pos, t, g);
    } else {
      int l = 1, r = n, pos = t;
      while (l <= r) {
        int mid = (l + r) / 2;
        if (querymx(1, 1, mid) >= g) {
          r = mid - 1;
        } else {
          l = mid + 1;
          pos = mid;
        }
      }
      ans += std::abs((g) * (pos - t + 1) - query(1, t, pos));
      setv(1, t, pos, g);
    }
  }
  cout << ans;
  return 0;
}