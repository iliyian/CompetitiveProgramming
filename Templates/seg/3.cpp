#include <bits/stdc++.h>
#define N 200001
#define int long long
using namespace std;

int a[N], llen[N << 2], rlen[N << 2], ans[N << 2];

void pushup(int s, int t, int p) {
  int mid = s + (t - s >> 1), ls = p << 1, rs = p << 1 | 1;
  llen[p] = llen[ls], rlen[p] = rlen[rs], ans[p] = max(ans[ls], ans[rs]);
  if (a[mid] != a[mid + 1]) {
    ans[p] = max(ans[p], rlen[ls] + llen[rs]);
    if (ans[ls] == mid - s + 1) llen[p] = mid - s + 1 + llen[rs];
    if (ans[rs] == t - mid) rlen[p] = t - mid + rlen[ls];
  }
}

void build(int s, int t, int p) {
  llen[p] = rlen[p] = ans[p] = 1;
  if (s == t) return;
  int mid = s + (t - s >> 1);
  build(s, mid, p << 1);
  build(mid + 1, t, p << 1 | 1);
  pushup(s, t, p);
}

void modify(int x, int l, int r, int p) {
  if (l == r && l == x) {
    a[x] = !a[x];
    return;
  }
  int mid = l + (r - l >> 1);
  if (x <= mid) modify(x, l, mid, p << 1);
  if (x > mid) modify(x, mid + 1, r, p << 1 | 1);
  pushup(l, r, p);
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  int n, q;
  cin >> n >> q;
  build(1, n, 1);
  for (int i = 0; i < q; i++) {
    int x;
    cin >> x;
    modify(x, 1, n, 1);
    cout << ans[1] << '\n';
  }
  return 0;
}