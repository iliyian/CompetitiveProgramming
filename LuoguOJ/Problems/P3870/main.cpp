#include <bits/stdc++.h>
#define N 100001
using namespace std;

int d[N * 4], b[N * 4];

void maintain(int s, int t, int p) {
  int mid = s + ((t - s) >> 1);
  d[p << 1] = mid - s + 1 - d[p << 1],
    d[(p << 1) | 1] = t - mid - d[(p << 1) | 1];
  b[p << 1] ^= 1, b[(p << 1) | 1] ^= 1;
  b[p] ^= 1;
}

void update(int l, int r, int s, int t, int p) {
  if (l <= s && t <= r) {
    d[p] = (t - s + 1) - d[p], b[p] ^= 1;
    return;
  }
  int mid = s + ((t - s) >> 1);
  if (b[p] && s != t) maintain(s, t, p);
  if (l <= mid) update(l, r, s, mid, p << 1);
  if (r > mid) update(l, r, mid + 1, t, (p << 1) | 1);
  d[p] = d[p << 1] + d[(p << 1) | 1];
}

int getSum(int l, int r, int s, int t, int p) {
  if (l <= s && t <= r) return d[p];
  int mid = s + ((t - s) >> 1), sum = 0;
  if (b[p]) maintain(s, t, p);
  if (l <= mid) sum += getSum(l, r, s, mid, p << 1);
  if (r > mid) sum += getSum(l, r, mid + 1, t, (p << 1) | 1);
  return sum;
}

int main() {
  freopen("data.in", "r", stdin);
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int c, a, b;
    cin >> c >> a >> b;
    if (c == 0) {
      update(a, b, 1, n, 1);
    } else {
      cout << getSum(a, b, 1, n, 1) << '\n';
    }
  }
  return 0;
}