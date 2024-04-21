#include <bits/stdc++.h>
#define int long long
#define lc p << 1
#define rc p << 1 | 1
#define eps 1e-10
using namespace std;

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n + 1);
  vector<double> inc(n + 2), v, d((n + 5) << 2);
  for (int i = 0; i <= n; i++) {
    cin >> a[i];
    if (i) {
      inc[i] = double(a[i] - a[i - 1]) / 10;
      v.push_back(inc[i]);
    }
  }
  inc[0] = -0x3f3f3f3f;
  inc[n + 1] = -0x3f3f3f3f;
  auto build = [&](auto self, int l, int r, int p) {
    if (l == r) {
      d[p] = inc[l];
      return;
    }
    int mid = l + (r - l >> 1);
    self(self, l, mid, lc);
    self(self, mid + 1, r, rc);
    d[p] = d[lc] + d[rc];
  };

  auto query = [&](auto self, int l, int r, int s, int t, int p) -> double {
    if (l <= s && t <= r) return d[p];
    int mid = s + (t - s >> 1);
    double ans = 0;
    if (l <= mid) ans += self(self, l, r, s, mid, lc);
    if (r > mid) ans += self(self, l, r, mid + 1, t, rc);
    return ans;
  };

  auto check = [&](const double &mid, const double &x) -> bool {
    int ilen = mid;
    if (mid < 1) {
      for (int i = 1; i <= n; i++) {
        if (inc[i] >= x) {
          return true;
        }
      }
      return false;
    }
    for (int l = 1; l <= n - ilen + 1; l++) {
      int r = l + ilen - 1;
      double summid = query(query, l, r, 1, n, 1);
      double rv = (summid + inc[r + 1] * (mid - ilen)) / mid;
      double lv = (summid + inc[l - 1] * (mid - ilen)) / mid;
      if (lv >= x || rv >= x) {
        return true;
      }
    }
    return false;
  };
  build(build, 1, n, 1);
  for (int t = 0; t < k; t++) {
    double x;
    cin >> x;
    double l = 0, r = n, ans = -1;
    while (l <= r) {
      double mid = (l + r) / 2.0;
      if (check(mid, x)) l = mid + eps, ans = mid;
      else r = mid - eps;
    }
    if (ans == -1) {
      cout << -1 << '\n';
    } else {
      cout << fixed << setprecision(20) << ans << '\n';
    }
  }
  // for (auto i : inc) {
  //   cout << i << ' ';
  // }
  // cout << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("B.in", "r", stdin);
  freopen("B.out", "w", stdout);

  int t = 1;

  while (t--) {
    solve();
  }

  return 0;
}