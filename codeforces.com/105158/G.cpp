#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n, k;
  cin >> n >> k;
  vector<vector<int>> ans(n + 2, vector<int>(n + 2));

  bool f = false;
  if (k & 1 ^ 1) {
    f = true;
    k--;
  }
  for (int y = 0; y <= n - 3; y++) {
    for (int x = (k - 1 + y * y - 2 * n * y) / 2; x + y + 3 <= n; x++) {
      int xcnt = max(0ll, 2 * x - 1);
      if (x >= 0 && y >= 0 && xcnt + 2 * n * y - y * y + 2 == k) {
        cout << x << ' ' << y << '\n';
      }
    }
  }
  cout << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("G.in", "r", stdin);
  freopen("G.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}