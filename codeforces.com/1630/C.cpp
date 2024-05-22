// date: 2024-05-20 17:26:20
// tag: 线段树优化dp

#include <bits/stdc++.h>
#define int long long
#define N ((int)2e5)
#define lc p << 1
#define rc p << 1 | 1
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;

int mx[(N + 5) << 2];

void pushup(int p) {
  mx[p] = max(mx[lc], mx[rc]);
}

void build(int l, int r, int p) {
  if (l == r) {
    mx[p] = -inf;
    return;
  }
  int mid = (l + r) / 2;
  build(l, mid, lc);
  build(mid + 1, r, rc);
  pushup(p);
}

int querymax(int l, int r, int s, int t, int p) {
  if (l <= s && t <= r) return mx[p];
  int mid = (s + t) / 2, ans = -inf;
  if (l <= mid) ans = max(ans, querymax(l, r, s, mid, lc));
  if (r > mid) ans = max(ans, querymax(l, r, mid + 1, t, rc));
  return ans;
}

void modify(int x, int s, int t, int p, int c) {
  if (x == s && x == t) {
    mx[p] = c;
    return;
  }
  int mid = (s + t) / 2;
  if (x <= mid) modify(x, s, mid, lc, c);
  else modify(x, mid + 1, t, rc, c);
  pushup(p);
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("C.in", "r", stdin);
  freopen("C.out", "w", stdout);

  int n;
  cin >> n;
  vector<int> a(n + 1), fst(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (!fst[a[i]]) {
      fst[a[i]] = i;
    }
  }
  // build(1, n, 1);
  vector<int> f(n + 1);
  modify(1, 1, n, 1, -1);
  for (int i = 2; i <= n; i++) {
    int l = fst[a[i]];
    if (!l || l == i) l = i - 1;
    int cur = querymax(l, i - 1, 1, n, 1) - 1;
    f[i] = cur + i;
    modify(i, 1, n, 1, cur);
  }
  cout << f[n] << '\n';

  return 0;
}