// date: 2023/12/10
// wa#0102: NEVER BELIEVE OBVIOUS THINGS
// wa#03: 不够贪心不够暴力没有考虑所有情况
// 没有注意到异常的数据范围：n <= 2000，这根本就意味着不可能是O(nlogn)的复杂度，太低了

#include <bits/stdc++.h>
#define N 2005
#define inf 0x3f3f3f3f3f3f3f3f
#define int long long
using namespace std;

int a[N], b[N];

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("C.in", "r", stdin);
  int _; cin >> _;
  while (_--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
      cin >> a[i];
    sort(a.begin(), a.end());

    int ans = a[0];
    if (k >= 3) {cout << 0 << '\n'; continue;}
    if (k == 1) {
      for (int i = 0; i < n; i++) {
        ans = min(ans, a[i]);
        for (int j = i + 1; j < n; j++)
          ans = min(ans, a[j] - a[i]);
      }
      cout << ans << '\n';
      continue;
    }
    
    for (int i = 0; i < n; i++) {
      ans = min(ans, a[i]);
      for (int j = i + 1; j < n; j++) {
        int v = a[j] - a[i];
        ans = min(ans, v);
        int idx = lower_bound(a.begin(), a.end(), v) - a.begin();
        if (idx < n) ans = min(ans, abs(v - a[idx]));
        if (idx > 0) ans = min(ans, abs(v - a[idx - 1]));
      }
    }
    cout << ans << '\n';
  }
}