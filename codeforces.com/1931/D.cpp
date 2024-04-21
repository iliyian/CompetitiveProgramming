// date: 2024/02/14 19:09:27
// tag: 模的简单性质

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n, x, y;
  cin >> n >> x >> y;
  vector<int> a(n + 1);
  map<pair<int, int>, int> m;
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    int mx = a[i] % x, my = a[i] % y;
    ans += m[{x - mx == 0 ? x : x - mx, my}];
    m[{mx == 0 ? x : mx, my}]++;
  }
  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("D.in", "r", stdin);
  freopen("D.out", "w", stdout);

  int t;
  cin >> t;

  while (t--) {
    solve();
  }
  return 0;
}