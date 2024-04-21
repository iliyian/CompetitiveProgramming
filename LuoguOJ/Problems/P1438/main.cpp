#include <bits/stdc++.h>
#define N 100002
#define int long long
using namespace std;

array<int, 4 * N> a, dat, d, b;

void build(int s, int t, int p) {
  if (s == t) {
    d[p] = dat[s];
    return;
  }
  int mid = s + (t - s >> 1);
  build(s, mid, p << 1);
  build(mid + 1, t, p << 1 | 1);
  d[p] = d[p << 1] + d[p << 1 | 1];
}

void maintain(int s, int t, int p) {
  int mid = s + (t - s >> 1);
  d[p << 1] += b[p] * (mid - s + 1), d[p << 1 | 1] += b[p] * (t - mid);
  b[p << 1] += b[p], b[p << 1 | 1] += b[p];
  b[p] = 0;
}

int query(int l, int r, int s, int t, int p) {
  if (l <= s && t <= r) return d[p];
  int mid = s + (t - s >> 1), sum = 0;
  if (b[p]) maintain(s, t, p);
  if (l <= mid) sum += query(l, r, s, mid, p << 1);
  if (r > mid) sum += query(l, r, mid + 1, t, p << 1 | 1);
  return sum;
}

void add(int l, int r, int s, int t, int p, int c) {
  if (l <= s && t <= r) {
    d[p] += (t - s + 1) * c, b[p] += c;
    return;
  }
  int mid = s + (t - s >> 1);
  if (b[p] && s != t) maintain(s, t, p);
  if (l <= mid) add(l, r, s, mid, p << 1, c);
  if (r > mid) add(l, r, mid + 1, t, p << 1 | 1, c);
  d[p] = d[p << 1] + d[p << 1 | 1];
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    dat[i] = a[i] - a[i - 1];
  }
  build(1, n, 1);
  for (int i = 0; i < m; i++) {
    int op, q, l, r, K, D;
    cin >> op;
    if (op == 1) {
      cin >> l >> r >> K >> D;
      add(l, l, 1, n, 1, K);
      if (l != r) add(l + 1, r, 1, n, 1, D);
      // 特殊值排除法
      if (r != n) add(r + 1, r + 1, 1, n, 1, - K - (r - l) * D);
    } else {
      cin >> q;
      cout << query(1, q, 1, n, 1) << '\n';
    }
  }
  return 0;
}