// date: 2024-05-31 18:20:24
// tag: 线段树优化dp，维护转移方程，区间加区间最值
// 线段树滚动（雾

#include <bits/stdc++.h>
#define int long long
#define lc p << 1
#define rc p << 1 | 1
#define N ((int)4e4)
using namespace std;

vector<vector<int>> f(N, vector<int>(51));
vector<int> d(N << 2), laz(N << 2);

void pushup(int p) {
  d[p] = max(d[lc], d[rc]);
}

void pushdown(int p) {
  if (laz[p]) {
    d[lc] += laz[p], d[rc] += laz[p];
    laz[lc] += laz[p], laz[rc] += laz[p];
    laz[p] = 0;
  }
}

void build(int l, int r, int p, int cur) {
  laz[p] = d[p] = 0;
  if (l == r) {
    d[p] = f[l - 1][cur]; //!!!!!
    return;
  }
  int mid = (l + r) / 2;
  build(l, mid, lc, cur);
  build(mid + 1, r, rc, cur);
  pushup(p);
}

void add(int l, int r, int s, int t, int p, int c) {
  if (l <= s && t <= r) {
    d[p] += c;
    laz[p] += c;
    return;
  }
  int mid = (s + t) / 2;
  pushdown(p);
  if (l <= mid) add(l, r, s, mid, lc, c);
  if (r > mid) add(l, r, mid + 1, t, rc, c);
  pushup(p);
};

int query(int l, int r, int s, int t, int p) {
  if (l <= s && t <= r) return d[p];
  int mid = (s + t) / 2, ans = 0;
  pushdown(p);
  if (l <= mid) ans = max(ans, query(l, r, s, mid, lc));
  if (r > mid) ans = max(ans, query(l, r, mid + 1, t, rc));
  return ans;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("B.in", "r", stdin);
  freopen("B.out", "w", stdout);

  int n, k;
  cin >> n >> k;
  vector<int> a(n + 1), pre(n + 1), pos(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    pre[i] = pos[a[i]];
    pos[a[i]] = i;
  }

  // f[n][k] = max(f[i][**k - 1**] + cnt[i + 1][n]) 
  // tmd，第29行查了好久啊
  for (int j = 1; j <= k; j++) {
    build(1, n, 1, j - 1);
    for (int i = 1; i <= n; i++) {
      add(pre[i] + 1, i, 1, n, 1, 1);
      f[i][j] = query(1, i, 1, n, 1);
    }
  }
  cout << f[n][k] << '\n';

  return 0;
}