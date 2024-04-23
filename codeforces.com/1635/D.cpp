// date: 2024-04-23 18:32:56
// tag: 位运算，dp

#include <bits/stdc++.h>
#define int long long
#define mod (int)(1e9 + 7)
using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("D.in", "r", stdin);
  freopen("D.out", "w", stdout);

  int n, p;
  cin >> n >> p;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  vector<array<int, 2>> dp(p + 1);
  vector<int> s(p + 1);
  dp[1][1] = 1;
  dp[2][0] = dp[2][1] = 1;
  for (int i = 3; i <= p; i++) {
    dp[i][1] = (dp[i - 1][0] + dp[i - 1][1]) % mod;
    dp[i][0] = (dp[i - 2][0] + dp[i - 2][1]) % mod;
  }
  for (int i = 1; i <= p; i++) {
    s[i] = ((s[i - 1] + dp[i][0]) % mod + dp[i][1]) % mod;
  }

  set<int> se;
  for (int i = 1; i <= n; i++) {
    if (p <= 30 && a[i] >= 1 << p) continue;
    se.insert(a[i]);
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    int x = a[i];
    if (p <= 30 && x >= 1 << p) continue;
    bool f = true;
    while (x % 4 == 0 || x & 1) {
      if (x == 0) break;
      if (x & 1) {
        x >>= 1;
      } else {
        x >>= 2;
      }
      if (se.count(x)) {
        f = false;
        break;
      }
    }
    if (f) {
      for (int j = 30; j >= 0; j--) {
        if (a[i] >> j & 1) {
          ans += (s[p - j - 1] + 1) % mod;
          ans %= mod;
          break;
        }
      }
    }
  }
  cout << ans << '\n';

  return 0;
}