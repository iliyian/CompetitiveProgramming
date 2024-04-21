// date: 2024/01/28 09:36:56
// tag: 挺神奇的没有tle

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n), b(m);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int i = 0; i < m; i++)
    cin >> b[i];
  sort(a.begin(), a.end());
  sort(b.begin(), b.end(), greater<int>());

  int ans = 0, sum = 0;
  for (int i = 0; i < n; i++) {
    sum += abs(a[i] - b[i]);
  }
  ans = max(ans, sum);
  for (int i = n - 1; i >= 0; i--) {
    sum = sum - abs(a[i] - b[i]) +
      abs(a[i] - b[m - (n - i)]);
    ans = max(ans, sum);
  }
  cout << ans << '\n';

  // int head = 0, tail = m - 1;
  // int ans = 0;
  // for (int i = 0; i < n; i++) {
  //   int x = abs(b[head] - a[i]), y = abs(b[tail] - a[i]);
  //   if (x > y && head) {
  //     ans += x;
  //     head++;
  //   } else {
  //     ans += y;
  //     tail--;
  //   }
  // }
  // cout << ans << '\n';

  // cout << n << ' ' << m << '\n';
  // for (int i = 0; i < n; i++)
  //   cout << a[i] << ' ';
  // cout << '\n';
  // for (int i = 0; i < m; i++)
  //   cout << b[i] << ' ';
  // cout << '\n';
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("D.in", "r", stdin);
  freopen("D.out", "w", stdout);
  int _; cin >> _;
  while (_--) solve();
}