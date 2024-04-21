// tmd看成异或了，白白多了两小时左右吧
// tmdtmdtmd！！

#include <bits/stdc++.h>
#define N 500005
#define int long long
using namespace std;

int a[N << 2], d[N << 2];

void pushup(int p) {
  if (d[p << 1] < 0) d[p] = d[p << 1 | 1];
  else if (d[p << 1 | 1] < 0) d[p] = d[p << 1];
  else d[p] = d[p << 1] | d[p << 1 | 1];
}

void build(int s, int t, int p) {
  if (s == t) {
    d[p] = a[s] < 0 ? 0 : a[s];
    return;
  }
  int mid = s + (t - s >> 1);
  build(s, mid, p << 1);
  build(mid + 1, t, p << 1 | 1);
  pushup(p);
}

int query(int l, int r, int s, int t, int p) {
  if (l <= s && t <= r) return d[p];
  int mid = s + (t - s >> 1), ans = 0;
  if (l <= mid) ans |= query(l, r, s, mid, p << 1);
  if (r > mid) ans |= query(l, r, mid + 1, t, p << 1 | 1);
  return ans;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("C.in", "r", stdin);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  build(1, n, 1);
  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int l, r;
    cin >> l >> r;
    cout << query(l, r, 1, n, 1) << '\n';
  }
  return 0;
}