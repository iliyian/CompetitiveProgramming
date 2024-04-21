#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n, k;
  cin >> n >> k;
  int ans = (k + 2) * (k + 1) / 2;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    if (x > k) continue;
    ans -= (k - x + 1) + (x / 2 + 1) - 1;
  }
  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("D.in", "r", stdin);
  freopen("D.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}