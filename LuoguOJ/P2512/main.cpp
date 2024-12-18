// date: 2024-03-12 20:55:51
// tag: ?
// mle#01: 费用流会mle
// wa#02: 符号搞错

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
  vector<int> a(n + 1), c(n + 1);
  int sum = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  int avg = sum / n;
  for (int i = 2; i <= n; i++) {
    c[i] = c[i - 1] + a[i] - avg;
  }
  sort(c.begin() + 1, c.end());
  int ans = 0, x1 = c[1 + n >> 1];
  for (int i = 1; i <= n; i++) {
    ans += abs(x1 - c[i]);
  }
  cout << ans << '\n';

  return 0;
}