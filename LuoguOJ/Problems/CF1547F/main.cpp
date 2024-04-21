// date: 2024-03-29 11:29:25
// tag: 线段树维护区间gcd，二分
// 第一次用线段树维护gcd，和第一次做O(nlog^{3}n)的时间复杂度的题...
// 也许是 O(nlogloglogn) ? 不管了，搞不懂

#include <bits/stdc++.h>
#define int long long
#define N 400005
#define lc p << 1
#define rc p << 1 | 1
using namespace std;

int g[N << 2], a[N], G = 0, n;

void pushup(int p) {
  g[p] = gcd(g[lc], g[rc]);
}

void build(int l, int r, int p) {
  if (l == r) {
    g[p] = a[l];
    return;
  }
  int mid = (l + r) / 2;
  build(l, mid, lc);
  build(mid + 1, r, rc);
  pushup(p);
}

int querygcd(int l, int r, int s, int t, int p) {
  if (l <= s && t <= r) return g[p];
  int mid = (s + t) / 2, ans = 0;
  if (l <= mid) ans = gcd(ans, querygcd(l, r, s, mid, lc));
  if (r > mid) ans = gcd(ans, querygcd(l, r, mid + 1, t, rc));
  return ans;
}

bool check(int mid) {
  for (int l = 1; l <= n; l++) {
    int r = l + mid - 1;
    int gg = querygcd(l, r, 1, n * 2, 1);
    if (gg > G) return false;
  }
  return true;
}

void solve() {
  cin >> n;
  G = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    a[i + n] = a[i];
    G = gcd(G, a[i]);
  }
  build(1, n * 2, 1);
  int l = 1, r = n, ans = -1;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (check(mid)) r = mid - 1, ans = mid;
    else l = mid + 1;
  }
  cout << ans - 1 << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}