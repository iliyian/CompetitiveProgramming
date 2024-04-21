#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n;
  cin >> n;
  int sum = 0, ans = -0x3f3f3f3f;
  for (int i = 1; i <= n; i++)
    sum += i * i;
  ans = max(ans, sum - n * n);
  int tot = sum;
  for (int len = 2; len <= n; len++) {
    int ma = 0;
    sum = tot;
    for (int i = n; i >= n - len + 1; i--)
      sum -= i * i;
    for (int i = 1; i <= len; i++) {
      int idx = n - len + i, v = n - i + 1;
      ma = max(ma, idx * v);
      sum += idx * v;
    }
    sum -= ma;
    ans = max(ans, sum);
  }
  cout << ans << '\n';
}
// 4
// 1 2 4 3
// 1 2 3 4
// 1 2 5 4 3
// 1 2 3 4 5
//      8 9 10
//      10 9 

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("C.in", "r", stdin);
  freopen("C.out", "w", stdout);
  int _; cin >> _;
  while (_--) solve();
}