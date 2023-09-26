// 线段树用处还挺多

#include <bits/stdc++.h>
#define N 100001
using namespace std;

int a[N * 4], b[N * 4], d[N * 4];

int getMin(int l, int r, int s, int t, int p) {
  if (l <= s && t <= r) return d[p];
  int mid = s + ((t - s) >> 1);
  int minn = 0x3f3f3f3f;
  if (l <= mid) minn = min(minn, getMin(l, r, s, mid, p << 1));
  if (r > mid) minn = min(minn, getMin(l, r, mid + 1, t, p << 1 | 1));
  return minn;
}

void build(int s, int t, int p) {
  if (s == t) {
    d[p] = a[s];
    return;
  }
  int mid = s + ((t - s) >> 1);
  build(s, mid, p << 1);
  build(mid + 1, t, p << 1 | 1);
  d[p] = min(d[p << 1], d[p << 1 | 1]);
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  build(1, n, 1);
  for (int i = 0; i < m; i++) {
    int l, r;
    cin >> l >> r;
    cout << getMin(l, r, 1, n, 1) << ' ';
  }
  return 0;
}