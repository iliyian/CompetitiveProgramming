// date: 2024-04-29 15:53:34
// tag: 动态二阶差分

#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("D.in", "r", stdin);
  freopen("D.out", "w", stdout);

  int n, k;
  cin >> n >> k;
  vector<int> a(n + 1), d(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int sum = 0, cnt = 0, ans = 0;
  for (int i = n; i >= 1; i--) {
    sum -= cnt;
    a[i] -= sum;
    cnt -= d[i];
    if (a[i] > 0) {
      int kk = min(k, i);
      int t = (a[i] - 1) / kk + 1;
      a[i] -= t * kk;
      ans += t;
      cnt += t;
      d[i - kk] += t;
      sum += kk * t;
    }
  }
  cout << ans << '\n';

  return 0;
}