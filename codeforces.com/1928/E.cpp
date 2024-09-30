#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n, x, y, s;
  cin >> n >> x >> y >> s;
  int r = x % y;
  if ((s - n * r) < 0 || (s - n * r) % y) {
    cout << "NO\n";
    return;
  }
  int sum = (s - n * r) / y;
  vector<int> dp(sum + 1, 0x3f3f3f3f);
  dp[0] = 0;
  for (int S = 0; S <= sum; S++) {
    for (int k = 1; S - k * (k + 1) / 2 >= 0; k++) {
      dp[S] = min(dp[S], dp[S - k * (k + 1) / 2] + k + 1);
    }
  }
  for (int i = 1, pre = x; i <= n && pre <= sum; pre += x + i, i++) {
    if (dp[sum - pre] <= n - i) {
      cout << "YES\n";
      sum -= pre;
      for (int j = 1; j <= i; j++) {
        cout << x + (j - 1) * y << ' ';
      }
      int len = n - i;
      while (sum) {
        for (int k = 1; k * (k + 1) / 2 <= sum; k++) {
          if (dp[sum - k * (k + 1) / 2] <= len) {
            
            sum -= k * (k + 1) / 2;
            len -= k + 1;
            break;
          }
        }
      }
      for (int j = 0; j < len; j++) {
        cout << r << ' ';
      }
      return;
    }
  }
  cout << "NO\n";
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("E.in", "r", stdin);
  freopen("E.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}