#include <algorithm>
#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector<int> a(n + 1), b(m + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= m; i++) {
    cin >> b[i];
  }

  sort(a.begin() + 1, a.end());
  sort(b.begin() + 1, b.end());
  int ans = 0, prv = 0;
  for (int i = 1; i <= m; i++) {
    int pos = lower_bound(a.begin() + prv + 1, a.end(), b[i]) - a.begin();
    if (pos == n + 1) {
      cout << -1 << '\n';
      return 0;
    }
    ans += a[pos];
    prv = pos;
  }
  cout << ans << '\n';

  return 0;
}