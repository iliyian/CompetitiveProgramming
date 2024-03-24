// date: 2024-03-15 12:52:12
// tag: 

#include <bits/stdc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  int n, k;
  cin >> n >> k;
  vector<int> t(k + 1), x(k + 1), y(k + 1);
  for (int i = 1; i <= k; i++) {
    cin >> t[i] >> x[i] >> y[i];
  }
  int ans = inf;
  for (int i = 1; i <= k; i++) {
    for (int j = i + 1; j <= k; j++) {
      int lc = lcm(t[i], t[j]);
      int hi = (x[i] + (lc / t[i] - 1) * y[i]) % n;
      int hj = (x[j] + (lc / t[j] - 1) * y[j]) % n;

      if (hi != hj) {
        ans = min(ans, lc);
        continue;
      }
      hi = (x[i] + (lc / t[i] * 2 - 1) * y[i]) % n;
      hj = (x[j] + (lc / t[j] * 2 - 1) * y[j]) % n;
      if (hi != hj) {
        ans = min(ans, lc * 2);
      }
    }
  }
  if (ans == inf) {
    cout << "Mystia will cook forever..." << '\n';
    return 0;
  }
  cout << ans - 1 << '\n';

  return 0;
}