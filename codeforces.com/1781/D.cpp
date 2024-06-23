// date: 2024-06-20 19:16:48
// tag: 数论，贪心

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a.begin() + 1, a.end());
  int ans = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      int d = a[j] - a[i];
      for (int p = 1; p * p < d; p++) {
        if (d % p == 0) {
          int p2 = d / p;
          int x = (p2 - p) * (p2 - p) / 4 - a[i];
          if (x >= 0) {
            int cur = 0;
            for (int k = 1; k <= n; k++) {
              int sqr = sqrt(a[k] + x);
              if (sqr * sqr == a[k] + x) {
                cur++;
              }
            }
            ans = max(ans, cur);
          }
        }
      }
    }
  }
  cout << ans << '\n';
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  freopen("D.in", "r", stdin);
  freopen("D.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}