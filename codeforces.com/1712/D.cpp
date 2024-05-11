// date: 2024-05-10 15:00:39
// tag: 二分，图论

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n + 1), pre(n + 1), suf(n + 2);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  auto check = [&](int mid) {
    int ans = n;
    for (int i = 1; i <= n; i++) {
      pre[i] = pre[i - 1] + (a[i] * 2 < mid);
      suf[n - i + 1] = suf[n - i + 2] + (a[n - i + 1] * 2 < mid);
    }
    for (int i = 1; i <= n - 1; i++) {
      ans = min(ans, pre[i - 1] + suf[i + 2]
         + !!(a[i] < mid) + !!(a[i + 1] < mid));
    }
    return ans <= k;
  };
  int l = 1, r = (int)1e9, ans = -1;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (check(mid)) l = mid + 1, ans = mid;
    else r = mid - 1;
  }
  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("D.in", "r", stdin);
  freopen("D.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}