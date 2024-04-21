// date: 2024-03-12 21:26:11
// tag: 贪心
// wa#01: 没有考虑到为了获取中位数已经将数组排序了

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
  vector<int> a(n + 1), c(n + 1), d(n + 1);
  int sum = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  int avg = sum / n;
  for (int i = 2; i <= n; i++) {
    c[i] = c[i - 1] + a[i] - avg;
    d[i] = c[i];
  }
  sort(d.begin() + 1, d.end());
  int ans = 0, x1 = d[1 + n >> 1];
  vector<int> x(n + 1);
  for (int i = 1; i <= n; i++) {
    ans += abs(x1 - c[i]);
    x[i] = x1 - c[i];
  }
  cout << ans << '\n';
  for (int i = 1; i <= n; i++) {
    int l = i - 1 ? i - 1 : n;
    cout << x[l] << ' ' << -x[i] << '\n';
  }
  return 0;
}