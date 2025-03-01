// date: 2024-03-24 16:38:07
// tag: 线段树，平方根性质

#include <bits/stdc++.h>
#define int long long
#define lc p << 1
#define rc p << 1 | 1
#define N 100005
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;

int sm[N << 2], mx[N << 2], a[N], n;

void pushup(int p) {
  sm[p] = sm[lc] + sm[rc];
  mx[p] = max(mx[lc], mx[rc]);
}

void build(int l, int r, int p) {
  if (l == r) {
    sm[p] = mx[p] = a[l];
    return;
  }
  int mid = (l + r) / 2;
  build(l, mid, lc);
  build(mid + 1, r, rc);
  pushup(p);
}

void update(int x, int l, int r, int p) {
  if (l == x && l == r) {
    sm[p] = sqrt(sm[p]);
    mx[p] = sm[p];
    return;
  }
  int mid = (l + r) / 2;
  if (x <= mid) update(x, l, mid, lc);
  else update(x, mid + 1, r, rc);
  pushup(p);
}

int querymax(int l, int r, int s, int t, int p) {
  if (l <= s && t <= r) return mx[p];
  int mid = (s + t) / 2, ans = -inf;
  if (l <= mid) ans = max(ans, querymax(l, r, s, mid, lc));
  if (r > mid) ans = max(ans, querymax(l, r, mid + 1, t, rc));
  return ans;
}

int querysum(int l, int r, int s, int t, int p) {
  if (l <= s && t <= r) return sm[p];
  int mid = (s + t) / 2, ans = 0;
  if (l <= mid) ans += querysum(l, r, s, mid, lc);
  if (r > mid) ans += querysum(l, r, mid + 1, t, rc);
  return ans;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int q;
  cin >> q;
  build(1, n, 1);
  for (int t = 0; t < q; t++) {
    int k, l, r;
    cin >> k >> l >> r;
    if (l > r) swap(l, r);
    if (k == 0) {
      if (querymax(l, r, 1, n, 1) == 1) {
        continue;
      }
      for (int i = l; i <= r; i++) {
        update(i, 1, n, 1);
      }
    } else {
      cout << querysum(l, r, 1, n, 1) << '\n';
    }
  }

  return 0;
}