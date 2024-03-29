#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    a[i] += a[i - 1];
  }
  int maxk = (sqrt(1 + 8 * n) - 1) / 2;
  vector<vector<int>> f(n + 1, vector<int>(maxk + 1));
  for (int i = 1; i <= n; i++) {
    f[i][1] = a[i] - a[i - 1];
  }
  for (int k = 2; k <= maxk; k++) {
    for (int i = n - k + 1; i >= 1; i--) {
      int sum = a[i + k - 1] - a[i - 1];
      if (i + k <= n && sum >= f[i + k][k - 1]) f[i][k] = f[i + 1][k];
      else f[i][k] = max(f[i + 1][k], sum);
    }
  }
  cout << f[1][maxk] << '\n';
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