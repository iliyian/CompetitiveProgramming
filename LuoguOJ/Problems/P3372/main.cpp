#include <bits/stdc++.h>
#define N 100001
#define int long long 
using namespace std;

int a[N * 4], b[N * 4], d[N * 4];

void build(int s, int t, int p) {
  if (s == t) {
    d[p] = a[s];
    return;
  }
  int mid = s + ((t - s) >> 1);
  build(s, mid, p << 1);
  build(mid + 1, t, p << 1 | 1);
  d[p] = d[p << 1] + d[p << 1 | 1];
}

void maintain(int s, int t, int p) {
  int mid = s + ((t - s) >> 1);
  d[p << 1] += b[p] * (mid - s + 1), d[p << 1 | 1] += b[p] * (t - mid);
  b[p << 1] += b[p], b[p << 1 | 1] += b[p];
  b[p] = 0;
}

int getSum(int l, int r, int s, int t, int p) {
  if (l <= s && t <= r) return d[p];
  int mid = s + ((t - s) >> 1), sum = 0;
  if (b[p]) maintain(s, t, p);
  if (l <= mid) sum += getSum(l, r, s, mid, p << 1);
  if (r > mid) sum += getSum(l, r, mid + 1, t, p << 1 | 1);
  return sum;
}

void update(int l, int r, int s, int t, int p, int c) {
  if (l <= s && t <= r) {
    d[p] += (t - s + 1) * c, b[p] += c;
    return;
  }
  int mid = s + ((t - s) >> 1);
  if (b[p] && s != t) maintain(s, t, p);
  if (l <= mid) update(l, r, s, mid, p << 1, c);
  if (r > mid) update(l, r, mid + 1, t, p << 1 | 1, c);
  d[p] = d[p << 1] + d[p << 1 | 1];
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  build(1, n, 1);
  for (int i = 0; i < m; i++) {
    int op, l, r, c;
    cin >> op >> l >> r;
    if (op == 1) {
      cin >> c;
      update(l, r, 1, n, 1, c);
    } else {
      cout << getSum(l, r, 1, n, 1) << '\n';
    }
  }
  return 0;
}