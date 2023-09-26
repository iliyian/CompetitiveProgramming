// 区间闭注意 -1

#include <bits/stdc++.h>
#define N 1000001
using namespace std;

int a[N], d[N * 4];

void build(int s, int t, int p) {
  if (s == t) {
    d[p] = a[s];
    return;
  };
  int mid = s + ((t - s) >> 1);
  build(s, mid, p << 1);
  build(mid + 1, t, p << 1 | 1);
  d[p] = min(d[p << 1], d[p << 1 | 1]);
}

int getMin(int l, int r, int s, int t, int p) {
  if (l <= s && t <= r) return d[p];
  int minn = 0x3f3f3f3f, mid = s + ((t - s) >> 1);
  if (l <= mid) minn = min(minn, getMin(l, r, s, mid, p << 1));
  if (r > mid) minn = min(minn, getMin(l, r, mid + 1, t, p << 1 | 1));
  return minn;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  build(1, n, 1);
  for (int i = 1; i <= n - m + 1; i++) {
    cout << getMin(i, i + m - 1, 1, n, 1) << '\n';
  }
  return 0;
}