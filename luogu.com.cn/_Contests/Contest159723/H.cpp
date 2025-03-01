#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("H.in", "r", stdin);
  freopen("H.out", "w", stdout);

  // dp[n][k] = dp[n - 1]
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> mem(n + 1, vector<int>(k + 1));
    auto dfs = [&mem](auto self, int p, int rest) -> int {
      if (mem[p][rest]) return mem[p][rest];
      if (p == 1) return mem[p][rest] = min(10ll, rest + 1);
      int sum = 0;
      for (int i = 0; i <= rest; i++) {
        sum += self(self, p - 1, rest - i);
      }
      return mem[p][rest] = sum;
    };
    int ans = 0;
    for (int i = 1; i <= min(9ll, k); i++) {
      ans += dfs(dfs, n, k - i);
    }
    cout << ans << '\n';
  }

  return 0;
}