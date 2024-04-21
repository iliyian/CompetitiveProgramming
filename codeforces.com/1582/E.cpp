// date: 2024-04-12 18:42:29
// tag: 动态规划

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1), s(n + 1);
  vector<vector<int>> f(n + 1, vector<int>(450));
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    s[i] = a[i] + s[i - 1];
    f[i][1] = a[i];
  }
  for (int i = n - 1; i >= 1; i--) {
    f[i][1] = max(f[i][1], f[i + 1][1]);
  }
  for (int i = n - 1; i >= 1; i--) {
    for (int k = 2; k * k + k <= n << 1 && i + k <= n; k++) {
      int sum = s[i + k - 1] - s[i - 1];
      assert(k < 450);
      if (sum < f[i + k][k - 1]) {
        f[i][k] = max(f[i + 1][k], sum);
      } else {
        f[i][k] = f[i + 1][k];
      }
    }
  }
  for (int k = 449; k >= 1; k--) {
    if (f[1][k]) {
      cout << k << '\n';
      return;
    }
  }
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