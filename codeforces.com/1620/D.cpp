// date: 2024-04-21 17:01:23
// tag: 暴力，枚举，分类讨论

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int ans = INT_MAX;
  for (int n1 = 0; n1 < 3; n1++) {
    for (int n2 = 0; n2 < 3; n2++) {
      int cnt = INT_MIN;
      bool f = true;
      for (int i = 1; i <= n; i++) {
        int cur = INT_MAX;
        bool ff = false;
        for (int i1 = 0; i1 <= n1; i1++) {
          for (int i2 = 0; i2 <= n2; i2++) {
            int t = a[i] - i1 - i2 * 2;
            if (t >= 0 && t % 3 == 0) {
              cur = min(cur, t / 3 + n1 + n2);
              ff = true;
            }
          }
        }
        if (!ff) {
          f = false;
          break;
        }
        cnt = max(cnt, cur);
      }
      if (f) {
        ans = min(ans, cnt);
      }
    }
  }
  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("D.in", "r", stdin);
  freopen("D.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}