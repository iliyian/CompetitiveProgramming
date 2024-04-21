// date: 2024/02/01 14:05:20
// tag: 暴力枚举两种操作所有可能的 操作次数 ，同时贪心即可
// wa#01: 括号扩错了，前半部分和搞成后半部分和了
// wa#02: 忘排序了
// wa#03: integer overflow

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n, k, m;
  cin >> n >> k >> m;
  vector<int> a(n + 1), s(n + 1);
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  sort(a.begin() + 1, a.end());
  for (int i = 1; i <= n; i++)
    s[i] = s[i - 1] + a[i];
  long double ans = -0x3f3f3f3f;
  for (int i = 0; i <= min(m, n - 1); i++)
    ans = max(ans, (long double)(s[n] - s[i] + min(m - i, k * (n - i))) / (n - i));
  cout << fixed << setprecision(20) << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("B.in", "r", stdin);
  freopen("B.out", "w", stdout);
  // int _; cin >> _;
  int _ = 1;
  while (_--) solve();
}