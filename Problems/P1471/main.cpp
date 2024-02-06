// date: 2024/02/05 23:33:52
// tag: 方差的计算与线段树模板，主要还是前者如何O(1)
// wa#01: 把数组的值和加减的值搞成整数了，改各种地方找了好久

#include <bits/stdc++.h>
#define N 100005
// #define double long double
#define lc p << 1
#define rc p << 1 | 1
using namespace std;

struct Node {
  double sum, sqrsum, add;
} nodes[N << 2];

double a[N];

void pushup(int p) {
  nodes[p].sum = nodes[lc].sum + nodes[rc].sum;
  nodes[p].sqrsum = nodes[lc].sqrsum + nodes[rc].sqrsum;
}

void build(int l, int r, int p) {
  if (l == r) {
    nodes[p] = {a[l], a[l] * a[l], 0};
    return;
  }
  int mid = l + (r - l >> 1);
  build(l, mid, lc);
  build(mid + 1, r, rc);
  pushup(p);
}

void rawpushdown(int s, int t, int p, double c) {
  nodes[p].sqrsum += nodes[p].sum * 2 * c + (t - s + 1) * c * c;
  nodes[p].sum += (t - s + 1) * c;
  nodes[p].add += c;
}

void pushdown(int s, int t, int p) {
  int mid = s + (t - s >> 1);
  rawpushdown(s, mid, lc, nodes[p].add);
  rawpushdown(mid + 1, t, rc, nodes[p].add);
  nodes[p].add = 0;
}

void add(int l, int r, int s, int t, int p, double c) {
  if (l <= s && t <= r) {
    rawpushdown(s, t, p, c);
    return;
  }
  int mid = s + (t - s >> 1);
  pushdown(s, t, p);
  if (l <= mid) add(l, r, s, mid, lc, c);
  if (r > mid) add(l, r, mid + 1, t, rc, c);
  pushup(p);
}

double sum(int l, int r, int s, int t, int p) {
  if (l <= s && t <= r) return nodes[p].sum;
  int mid = s + (t - s >> 1);
  double ans = 0;
  pushdown(s, t, p);
  if (l <= mid) ans += sum(l, r, s, mid, lc);
  if (r > mid) ans += sum(l, r, mid + 1, t, rc);
  return ans;
}

double sqrsum(int l, int r, int s, int t, int p) {
  if (l <= s && t <= r) return nodes[p].sqrsum;
  int mid = s + (t - s >> 1);
  double ans = 0;
  pushdown(s, t, p);
  if (l <= mid) ans += sqrsum(l, r, s, mid, lc);
  if (r > mid) ans += sqrsum(l, r, mid + 1, t, rc);
  return ans;
}

void solve() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  build(1, n, 1);
  for (int i = 0; i < m; i++) {
    int op, x, y;
    double k;
    cin >> op;
    if (op == 1) {
      cin >> x >> y >> k;
      add(x, y, 1, n, 1, k);
    } else if (op == 2) {
      cin >> x >> y;
      cout << fixed << setprecision(4)
           << sum(x, y, 1, n, 1) / (y - x + 1) << '\n';
    } else {
      cin >> x >> y;
      double avg = sum(x, y, 1, n, 1) / (y - x + 1);
      cout << fixed << setprecision(4)
           << sqrsum(x, y, 1, n, 1) / (y - x + 1) - avg * avg << '\n';
    }
  }
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);
  // int _; cin >> _;
  int _ = 1;
  while (_--) solve();
}