// date: 2024-03-12 21:03:49
// tag: ？

#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  int n;
  cin >> n;
  vector<int> a(n + 1), b(n + 1), c(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i] >> b[i];
    if (i > 1)
      c[i] = c[i - 1] + a[i] - b[i];
  }
  sort(c.begin() + 1, c.end());
  int ans = 0, x1 = c[1 + n >> 1];
  for (int i = 1; i <= n; i++) {
    ans += abs(x1 - c[i]);
  }
  cout << ans << '\n';

  return 0;
}