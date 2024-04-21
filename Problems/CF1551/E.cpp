// date: 2024-04-01 15:40:04
// tag: 动态规划

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n, k;
  cin >> n >> k;
  vector<vector<int>> f(n + 1, vector<int>(n + 1));
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int ans = INT_MAX;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= i; j++) {
      f[i][j] = max(f[i - 1][j], f[i - 1][j - 1] + (a[i] == j));
      if (f[i][j] == k) {
        ans = min(ans, i - j);
      }
    }
  }
  cout << (ans == INT_MAX ? -1 : ans) << '\n';
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