// date: 2024-05-11 20:55:20
// tag: dp带方案统计

#include <bits/stdc++.h>
#define int long long
#define mod 998244353
using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("D.in", "r", stdin);
  freopen("D.out", "w", stdout);

  int n, k;
  cin >> n >> k;
  vector<vector<int>> f(2, vector<int>(n + 1));
  vector<int> ans(n + 1);
  int cur = 1;
  for (int j = 1; j * k <= n; j++) {
    f[cur][j * k] = 1;
    ans[j * k]++;
  }
  // f[0][0] = 1;
  cur ^= 1;
  for (int i = 2;; i++) {
    if ((k + k + i - 1) * i / 2 > n) break;
    for (int j = 1; j <= n; j++) {
      f[cur][j] = 0;
      if (j > k + i - 1) {
        f[cur][j] +=
          (f[cur ^ 1][j - (k + i - 1)] + f[cur][j - (k + i - 1)]) % mod;
        f[cur][j] %= mod;
      }
      // cout << f[cur][j] << ' ';
      ans[j] += f[cur][j];
      ans[j] %= mod;
    }
    cur ^= 1;
    // cout << '\n';
  }
  // for (int i = 1; i <= n; i++) {
  //   cout << f[cur ^ 1][i] << " \n"[i == n];
  // }
  for (int i = 1; i <= n; i++) {
    cout << ans[i] << " \n"[i == n];
  }

  return 0;
}