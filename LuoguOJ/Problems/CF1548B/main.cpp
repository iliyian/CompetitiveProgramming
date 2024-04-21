#include <bits/stdc++.h>
#define int long long
#define N 200005
#define lc p << 1
#define rc p << 1 | 1
using namespace std;

int a[N], g[N << 2], d[N], n;

void pushup(int p) {
  g[p] = gcd(g[lc], g[rc]);
}

void build(int l, int r, int p) {
  if (l == r) {
    g[p] = d[l];
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
  for (int l = 2; l + mid - 1 <= n; l++) {
    int r = l + mid - 1;
    if (querygcd(l, r, 2, n, 1) > 1) {
      return true;
    }
  }
  return false;
}

void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    d[i] = a[i] - a[i - 1];
  }
  if (n == 1) {
    cout << 1 << '\n';
    return;
  }
  build(2, n, 1);
  int ans = 0;
  for (int r = 2, l = r; r <= n; r++) {
    while (l <= r && querygcd(l, r, 2, n, 1) == 1) {
      l++;
    }
    if (l <= r) {
      ans = max(ans, r - l + 1);
    }
  }
  cout << ans + 1 << '\n';
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