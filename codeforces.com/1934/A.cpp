#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1), d(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a.begin() + 1, a.end());
  int ans = 0;
  ans = abs(a[1] - a[n]) + abs(a[n] - a[2])
    + abs(a[2] - a[n - 1]) + abs(a[n - 1] - a[1]);
  // for (int i = 1; i <= n; i++) {
  //   for (int j = 1; j <= n; j++) {
  //     for (int k = 1; k <= n; k++) {
  //       for (int l = 1; l <= n; l++) {
  //         if (i == j || i == k || i == l) continue;
  //         if (j == k || j == l) continue;
  //         if (k == l) continue;
  //         ans = max(ans, abs(a[i] - a[j]) + abs(a[j] - a[k]) + abs(a[k] - a[l]) + abs(a[l] - a[i]));
  //       }
  //     }
  //   }
  // }
  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("A.in", "r", stdin);
  freopen("A.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}