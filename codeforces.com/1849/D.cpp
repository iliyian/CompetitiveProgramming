#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1);
  // dp[i] = dp[i - a[i]]
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("D.in", "r", stdin);
  freopen("D.out", "w", stdout);

  int t = 1;

  while (t--) {
    solve();
  }

  return 0;
}