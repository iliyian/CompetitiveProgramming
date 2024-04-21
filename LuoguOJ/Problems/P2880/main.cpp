#include <bits/stdc++.h>
#define N 50001
using namespace std;

int a[N], b[N * 4], mind[N * 4], maxd[N * 4];

void build(int s, int t, int p) {
  int mid = s + (t - s >> 1);
  if (s == t) {
    mind[p] = maxd[p] = a[s];
    return;
  }
  build(s, mid, p << 1);
  build(mid + 1, t, p << 1 | 1);
  mind[p] = min(mind[p << 1], mind[p << 1 | 1]);
  maxd[p] = max(maxd[p << 1], maxd[p << 1 | 1]);
}

int getx(int l, int r, int s, int t, int p, bool f) {
  if (l <= s && t <= r) return f ? maxd[p] : mind[p];
  int ans = f ? -1 : 0x3f3f3f3f, mid = s + (t - s >> 1);
  if (l <= mid) 
    ans = f 
      ? max(ans, getx(l, r, s, mid, p << 1, f)) 
      : min(ans, getx(l, r, s, mid, p << 1, f));
  if (r > mid)
    ans = f
      ? max(ans, getx(l, r, mid + 1, t, p << 1 | 1, f))
      : min(ans, getx(l, r, mid + 1, t, p << 1 | 1, f));
  return ans;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  int n, q;
  cin >> n >> q;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  build(1, n, 1);
  for (int i = 0; i < q; i++) {
    int l, r;
    cin >> l >> r;
    cout << getx(l, r, 1, n, 1, true) - getx(l, r, 1, n, 1, false) << '\n';
  }
  return 0;
}