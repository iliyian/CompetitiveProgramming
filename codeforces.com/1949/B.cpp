// date: 2024-03-27 14:50:33
// tag: 暴力，思维

#include <bits/stdc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1), b(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
  }
  sort(a.begin() + 1, a.end());
  sort(b.begin() + 1, b.end());
  int ans = -inf;
  for (int t = 1; t <= n; t++) {
    int cur = inf;
    for (int i = 1; i <= n; i++) {
      if (i <= t) cur = min(cur, abs(a[i] - b[i + n - t]));
      else cur = min(cur, abs(a[i] - b[i - t]));
    }
    ans = max(ans, cur);
  }
  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("B.in", "r", stdin);
  freopen("B.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}