#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a = {-1};
  for (int i = 1; i <= n; i++) {
    if (n % i == 0) {
      a.push_back(i);
    }
  }
  vector<vector<int>> dp(a.size() + 1, vector<int>(a.size() + 1));
  dp[1][1] = 1;
  for (int i = 2; i < a.size(); i++) {
    for (int j = 2; j <= i; j++) {
      dp[i][j] = dp[i][j - 1] + (i == j);
      if (a[i] % a[j] == 0) {
        dp[i][j] += dp[a[i] / a[j]][j] - 1;
      }
    }
  }
  cout << dp[a.size()][a.size()] - 1 << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}