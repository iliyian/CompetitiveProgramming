// date: 2024-05-08 12:11:54
// tag: 递推，构造

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1);
  int sum = 0, mn = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    sum += a[i];
    mn = max(mn, (sum + i - 1) / i);
  }
  int q;
  cin >> q;
  for (int _ = 1; _ <= q; _++) {
    int t;
    cin >> t;
    int ans = (sum + t - 1) / t;
    if (t < mn) {
      cout << -1 << '\n';
    } else {
      cout << ans << '\n';
    }
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("D.in", "r", stdin);
  freopen("D.out", "w", stdout);

  solve();

  return 0;
}