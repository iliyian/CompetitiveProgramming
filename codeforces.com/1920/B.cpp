// date: 2024/01/30 21:47:23
// tag: wa#01: 样例没检查就交上去了，枚举范围搞错
// 很水的前缀和，贪心即可

#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, k, x;
  cin >> n >> k >> x;
  vector<int> a(n + 1), s(n + 1);
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  sort(a.begin() + 1, a.end());
  for (int i = 1; i <= n; i++)
    s[i] = s[i - 1] + a[i];
  
  int ans = -0x3f3f3f3f;
  for (int i = 0; i <= k; i++)
    ans = max(ans, s[max(0, n - i - x)] - (s[n - i] - s[max(0, n - i - x)]));

  // if (k == n) ans = max(ans, 0);
  cout << ans << '\n';


  // cout << n << ' ' << k << ' ' << x << '\n';
  // for (int i = 0; i < n; i++)
    // cout << a[i] << " \n"[i == n - 1];
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("B.in", "r", stdin);
  freopen("B.out", "w", stdout);
  int _; cin >> _;
  while (_--) solve();
}