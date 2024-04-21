#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("A.in", "r", stdin);
  freopen("A.out", "w", stdout);

  int n, q;
  cin >> n >> q;
  vector<int> a(n + 1), v;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    v.push_back(a[i]);
  }
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());

  auto lo = [&](int x) {
    return lower_bound(v.begin(), v.end(), x) - v.begin();
  };
  auto up = [&](int x) {
    return upper_bound(v.begin(), v.end(), x) - v.begin();
  };

  for (int _ = 1; _ <= q; _++) {
    int p, k;
    cin >> p >> k;
    int l = 0, r = 2e9 + 10, ans = -1;
    while (l <= r) {
      int mid = (l + r) / 2;
      int rcnt = up(p + mid) - 1 - (lo(p) - 1);
      int lcnt = up(p) - 1 - (lo(p - mid) - 1);
      int sum = rcnt + lcnt - (v[lo(p)] == p);
      if (sum >= k) r = mid - 1, ans = mid;
      else l = mid + 1;
    }
    cout << ans << '\n';
  }

  return 0;
}