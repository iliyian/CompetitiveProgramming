// date: 2024-05-28 22:14:03
// tag: dp

#include <bits/stdc++.h>
#define int long long
#define N ((int)1e6)
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a = {-1};
  for (int i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      a.push_back(i);
      if (i * i != n) {
        a.push_back(n / i);
      }
    }
  }
  sort(a.begin(), a.end());
  vector<int> id1(N + 1), id2(N + 1);

  int s = sqrt(n);
  for (int i = 1; i < a.size(); i++) {
    int v = a[i];
    if (v <= s) {
      id1[v] = i;
    } else {
      id2[n / v] = i;
    }
  }

  vector<vector<int>> dp(a.size(), vector<int>(a.size()));
  for (int i = 1; i < a.size(); i++) {
    dp[i][i] = 1;
    for (int j = 1; j < a.size(); j++) {
      dp[i][j] += dp[i][j - 1];
      if (i <= j) continue;
      if (a[i] % a[j] == 0) {
        int v = a[i] / a[j];
        dp[i][j] += dp[v <= s ? id1[v] : id2[n / v]][j - 1];
      }
    }
  }
  cout << dp.back().back() - 1 << '\n';
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