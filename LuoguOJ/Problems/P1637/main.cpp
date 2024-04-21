// 桶做的线段树，太妙了
// 线段树务必tmd四倍空间，凡有莫名其妙的数字必然是越界了

#include <bits/stdc++.h>
#define N 30003
#define int long long
using namespace std;

int a[N << 2], v[N << 2], id[N << 2], sum[N << 2], leftc[N << 2], rightc[N << 2];

void pushup(int p) {
  sum[p] = sum[p << 1] + sum[p << 1 | 1];
}

void update(int s, int t, int p, int i) {
  if (s == t && s == i) {
    sum[p]++;
    return;
  }
  int mid = s + (t - s >> 1);
  if (mid >= i) update(s, mid, p << 1, i);
  if (mid < i) update(mid + 1, t, p << 1 | 1, i);
  pushup(p);
}

int query(int l, int r, int s, int t, int p) {
  if (l <= s && t <= r) return sum[p];
  int mid = s + (t - s >> 1), ans = 0;
  if (l <= mid) ans += query(l, r, s, mid, p << 1);
  if (r > mid) ans += query(l, r, mid + 1, t, p << 1 | 1);
  return ans;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  int n, vlen = 0;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    v[++vlen] = a[i];
  }
  sort(v + 1, v + vlen + 1);
  int len = unique(v + 1, v + vlen + 1) - v - 1;

  for (int i = 1; i <= n; i++) {
    id[i] = lower_bound(v + 1, v + len + 1, a[i]) - v;
  }

  for (int i = 1; i <= n; i++) {
    if (id[i] > 1)
      leftc[i] = query(1, id[i] - 1, 1, n, 1);
    update(1, n, 1, id[i]);
  }
  memset(sum, 0, sizeof(sum));

  int ans = 0;
  for (int i = n; i >= 1; i--) {
    if (id[i] < n)
      rightc[i] = query(id[i] + 1, n, 1, n, 1);
    update(1, n, 1, id[i]);
  }
  for (int i = 1; i <= n; i++) {
    ans += leftc[i] * rightc[i];
  }

  cout << ans;
  return 0;
}