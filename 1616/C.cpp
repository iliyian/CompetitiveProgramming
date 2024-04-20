// date: 2024-04-19 16:42:53
// tag: 暴力，构造

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
  vector<vector<int>> f(n + 1, vector<int>(201, 1));
  int ans = 1;
  for (int l = 1; l <= n; l++) {
    for (int r = l + 1; r <= n; r++) {
      int cnt = 2;
      for (int i = l + 1; i < r; i++) {
        if ((a[r] - a[i]) * (i - l) == (a[i] - a[l]) * (r - i)) {
          cnt++;
        }
      }
      ans = max(ans, cnt);
    }
  }
  cout << n - ans << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("C.in", "r", stdin);
  freopen("C.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}