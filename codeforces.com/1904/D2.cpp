// date: 2024-03-05 21:51:58
// tag: 
// 关键在于搞清楚如何转移，也就是真正的tmd条件，这tmd

#include <bits/stdc++.h>
#define int long long
#define lc p << 1
#define rc p << 1 | 1
using namespace std;

vector<int> mn, mx, a, b;

void pushup(int p) {
  mx[p] = max(mx[lc], mx[rc]);
  mn[p] = min(mn[lc], mn[rc]);
}

void build(int l, int r, int p) {
  if (l == r) {
    mx[p] = a[l], mn[p] = b[l];
    return;
  }
  int mid = l + (r - l >> 1);
  build(l, mid, lc);
  build(mid + 1, r, rc);
  pushup(p);
}

int querymin(int l, int r, int s, int t, int p) {
  if (l <= s && t <= r) {
    return mn[p];
  }
  int mid = s + t >> 1, ans = INT_MAX;
  if (l <= mid) ans = min(ans, querymin(l, r, s, mid, lc));
  if (r > mid) ans = min(ans, querymin(l, r, mid + 1, t, rc));
  return ans;
}

int querymax(int l, int r, int s, int t, int p) {
  if (l <= s && t <= r) {
    return mx[p];
  }
  int mid = s + t >> 1, ans = INT_MIN;
  if (l <= mid) ans = max(ans, querymax(l, r, s, mid, lc));
  if (r > mid) ans = max(ans, querymax(l, r, mid + 1, t, rc));
  return ans;
}

void solve() {
  int n;
  cin >> n;
  a.resize(n + 1), b.resize(n + 1);
  mn.resize(n + 5 << 2), mx.resize(n + 5 << 2);
  set<pair<int, int>> s;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
  }
  build(1, n, 1);
  vector<bool> ok(n + 1);
  vector<int> p(n + 1);
  for (int i = 1; i <= n; i++) {
    p[a[i]] = i;
    if (!p[b[i]]) continue;
    if (querymin(p[b[i]], i, 1, n, 1) >= b[i] &&
      querymax(p[b[i]], i, 1, n, 1) <= b[i])
        ok[i] = true;
  }
  fill(p.begin(), p.end(), 0);
  for (int i = n; i >= 1; i--) {
    p[a[i]] = i;
    if (!p[b[i]]) continue;
    if (querymin(i, p[b[i]], 1, n, 1) >= b[i] &&
      querymax(i, p[b[i]], 1, n, 1) <= b[i])
        ok[i] = true;
  }
  for (int i = 1; i <= n; i++) {
    if (!ok[i]) {
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("D2.in", "r", stdin);
  freopen("D2.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}