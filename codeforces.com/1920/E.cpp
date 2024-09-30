// date: 2024/01/30 20:20:50
// tag: 标准的动态规划，关键在于依据分割的特性找到计算sum的方法，
// 数组相邻乘积和，然后枚举 数组结尾 与 sum 两信息即可。
// dp不就是暴力循环嘛

#include <bits/stdc++.h>
#define mod 998244353
#define int long long
using namespace std;

void solve() {
  int n, k;
  cin >> n >> k;
  vector<vector<int>> f(n + 1, vector<int>(k + 1));
  int ans = 0;
  fill(f[0].begin(), f[0].end(), 1);
  for (int sum = 1; sum <= n; sum++) {
    for (int cur = 1; cur <= k; cur++) {
      for (int prv = 1; prv <= min(k - cur + 1, sum / cur); prv++) {
        f[sum][cur] = (f[sum][cur] + f[sum - cur * prv][prv] % mod) % mod;
      }
      if (sum == n) {
        ans = (ans + f[sum][cur] % mod) % mod;
      }
    }
  }
  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  // freopen("E.in", "r", stdin);
  // freopen("E.out", "w", stdout);
  int _; cin >> _;
  while (_--) solve();
}